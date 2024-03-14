//
// Created by volodya on 14.03.24.
//

#ifndef APP_LOADER_PACKAGEJSON_H_
#define APP_LOADER_PACKAGEJSON_H_

#include <memory>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include "../ir_builder/Package.h"

struct PackagesDetails {
  std::map<std::string, Package> packages = {};
};

class PackageJson {

 public:
  int Export(PackagesDetails);
  PackagesDetails Import();

 private:
 public:
  explicit PackageJson(std::ostream *stream);
  explicit PackageJson(std::istream *stream, llvm::LLVMContext *llvm_context);
  PackageJson(std::ostream *ostream, std::istream *istream, llvm::LLVMContext *llvm_context);
 private:
  PackagesDetails _packages;
  std::ostream *_ostream = nullptr;
  std::istream *_istream = nullptr;
  llvm::LLVMContext *context = nullptr;

  boost::property_tree::ptree exportPackage(Package &a_package);
  Package importPackage(boost::property_tree::ptree tree);

  boost::property_tree::ptree exportType(TypeWrapper wrapper);
  TypeWrapper importType(boost::property_tree::ptree tree);

  FunctionWrapper importFunction(boost::property_tree::ptree tree);
  boost::property_tree::ptree exportFunction(const FunctionWrapper& wrapper);

};

#endif //APP_LOADER_PACKAGEJSON_H_
