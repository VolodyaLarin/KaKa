//
// Created by volodya on 14.03.24.
//

#include "PackageJson.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <utility>

namespace pt = boost::property_tree;

PackageJson::PackageJson(std::ostream *stream)
    : _ostream(stream) {

}

PackageJson::PackageJson(std::istream *stream, llvm::LLVMContext *llvm_context)
    : _istream(stream), context(llvm_context) {

}

PackageJson::PackageJson(std::ostream *ostream, std::istream *istream, llvm::LLVMContext *llvm_context)
    : _ostream(ostream), _istream(istream), context(llvm_context) {}

int PackageJson::Export(PackagesDetails details) {
  if (!_ostream) return -1;

  pt::ptree tree;

  pt::ptree packages;

  for (auto &package : details.packages) {
    pt::ptree node = this->exportPackage(package.second);
    packages.add_child(package.first, node);
  }
  tree.add_child("packages", packages);

  pt::write_json(*_ostream, tree);

  return 0;
}

PackagesDetails PackageJson::Import() {
  PackagesDetails details = {};

  pt::ptree tree;
  pt::read_json(*_istream, tree);

  auto packages = tree.get_child("packages");

  for (const auto &node : packages) {
    auto package = importPackage(node.second);
    details.packages.insert({node.first, package});
  }

  return details;
}

pt::ptree PackageJson::exportPackage(Package &a_package) {
  pt::ptree tree;

  tree.put("nameHash", a_package.GetNameHash());

  pt::ptree types;
  for (auto &ty : a_package.GetTypes()) {
    pt::ptree node = exportType(ty.second);
    types.add_child(ty.first, node);
  }
  tree.add_child("types", types);

  pt::ptree functions;
  for (auto &ty : a_package.GetFunctions()) {
    pt::ptree node = exportFunction(ty.second);
    functions.add_child(ty.first, node);
  }
  tree.add_child("functions", functions);

  return tree;
}

Package PackageJson::importPackage(boost::property_tree::ptree tree) {
  Package a_package = {"", tree.get<std::string>("nameHash")};

  for (const auto &type : tree.get_child("types")) {
    a_package.GetTypes().insert({type.first, importType(type.second)});
  }

  for (const auto &type : tree.get_child("functions")) {
    a_package.GetFunctions().insert({type.first, importFunction(type.second)});
  }

  return a_package;
}

pt::ptree PackageJson::exportType(TypeWrapper wrapper) {
  pt::ptree tree;

  if (wrapper.getTypeDetails().intInfo) {
    tree.put("type", "int");
    tree.put<int>("integer.size", wrapper.getTypeDetails().intInfo->bitSize);
    tree.put<bool>("integer.signed", wrapper.getTypeDetails().intInfo->isSigned);
    return tree;
  }
  if (wrapper.getTypeDetails().floatInfo) {
    tree.put("type", "float");
    tree.put<int>("float.size", wrapper.getTypeDetails().floatInfo->bitSize);
    return tree;
  }

  if (wrapper.getTypeDetails().structInfo) {
    auto st = *wrapper.getTypeDetails().structInfo;
    tree.put("type", "struct");
    tree.put<bool>("struct.interface", st.isInterface);

    auto fieldsCount = st.fields.size();
    pt::ptree fields;
    for (int i = 0; i < fieldsCount; i++) {
      pt::ptree fieldTree;
      fieldTree.put("name", st.fieldNames[i]);

      auto typeTree = exportType(st.fields[i]);
      fieldTree.add_child("type", typeTree);
      fields.push_back(std::make_pair("", fieldTree));
    }
    tree.add_child("struct.fields", fields);
    return tree;
  }

  if (wrapper.getTypeDetails().functionInfo) {
    auto st = *wrapper.getTypeDetails().functionInfo;
    tree.put("type", "function");
    tree.put("function.vararg", st.isVarargs);
    pt::ptree arguments;
    for (const auto &arg : st.arguments) {
      pt::ptree argtree = exportType(arg);

      arguments.push_back(std::make_pair("", argtree));
    }
    tree.add_child("function.arguments", arguments);

    if (st.retType) {
      tree.add_child("function.ret_type", exportType(*st.retType));
    }
    return tree;
  }

  if (wrapper.getTypeDetails().pointerInfo) {
    tree.put("type", "pointer");
    if (!wrapper.getTypeDetails().pointerInfo->type) {
      return tree;
    }
    auto subtype = exportType(*wrapper.getTypeDetails().pointerInfo->type);
    tree.add_child("pointer.type", subtype);
    return tree;
  }

  if (wrapper.getTypeDetails().arrayInfo) {
    tree.put("type", "array");
    auto subtype = exportType(*wrapper.getTypeDetails().arrayInfo->type);
    tree.add_child("array.type", subtype);
    tree.put("array.size", wrapper.getTypeDetails().arrayInfo->size);
    return tree;
  }

  return tree;
}

TypeWrapper PackageJson::importType(boost::property_tree::ptree tree) {
  auto type = tree.get<std::string>("type");

  if (type == "int") {
    return TypeWrapper::GetInt(tree.get<bool>("integer.signed"), tree.get<int>("integer.size"));
  }
  if (type == "float") {
    return TypeWrapper::GetFloat(tree.get<int>("float.size") == 64);
  }
  if (type == "pointer") {
    std::optional<TypeWrapper> ptrType;
    auto pointerTree = tree.get_child("pointer");
    if (pointerTree.find("type") != pointerTree.not_found()) {
      ptrType = importType(tree.get_child("pointer.type"));
    }
    return TypeWrapper::GetPointer(ptrType);
  }
  if (type == "array") {
    auto ptrType = importType(tree.get_child("array.type"));
    size_t size = tree.get<int>("array.size");
    return ptrType.getArrayOf(size);
  }
  if (type == "struct") {
    std::vector<std::pair<std::string, TypeWrapper>> fields;

    for (auto f : tree.get_child("struct.fields")) {
      auto fName = f.second.get<std::string>("name");
      auto fType = importType(f.second.get_child("type"));
      fields.emplace_back(fName, fType);
    }

    return TypeWrapper::GetStruct(fields, tree.get<bool>("struct.interface"));
  }

  if (type == "function") {
    std::vector<TypeWrapper> args;

    for (const auto &f : tree.get_child("function.arguments")) {
      auto fType = importType(f.second);
      args.emplace_back(fType);
    }
    std::optional<TypeWrapper> retType;
    auto functionTree = tree.get_child("function");
    if (functionTree.find("ret_type") != functionTree.not_found()) {
      retType = importType(tree.get_child("function.ret_type"));
    }

    return TypeWrapper::GetFunction(retType, args, tree.get<bool>("function.vararg"));
  }

  return TypeWrapper::GetPointer({});
}

pt::ptree PackageJson::exportFunction(const FunctionWrapper& wrapper) {
  pt::ptree tree;

  tree.put("link", wrapper.LinkName);
  tree.add_child("type", exportType(wrapper.type));

  return tree;
}
FunctionWrapper PackageJson::importFunction(boost::property_tree::ptree tree) {
  FunctionWrapper func = {tree.get<std::string>("link"), importType(tree.get_child("type"))};
  return func;
}
