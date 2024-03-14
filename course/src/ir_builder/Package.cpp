//
// Created by volodya on 14.03.24.
//

#include "Package.h"

#include <utility>
const std::string &Package::GetName() const {
  return name;
}
std::map<std::string, TypeWrapper> &Package::GetTypes() {
  return types;
}
std::map<std::string, FunctionWrapper> &Package::GetFunctions() {
  return functions;
}
const std::string &Package::GetNameHash() const {
  return nameHash;
}
Package::Package(std::string name, std::string name_hash) : name(std::move(name)), nameHash(std::move(name_hash)) {}
