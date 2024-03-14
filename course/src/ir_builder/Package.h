//
// Created by volodya on 14.03.24.
//

#ifndef APP_IR_BUILDER_PACKAGE_H_
#define APP_IR_BUILDER_PACKAGE_H_

#include <string>
#include <vector>
#include "FunctionWrapper.h"
class Package {
  std::string name;
  std::string nameHash;
  std::map<std::string, TypeWrapper> types;
  std::map<std::string, FunctionWrapper> functions;
 public:
  Package(std::string name, std::string name_hash);
 public:
  [[nodiscard]] const std::string &GetName() const;
  std::map<std::string, TypeWrapper> &GetTypes();
  std::map<std::string, FunctionWrapper> &GetFunctions();
  [[nodiscard]] const std::string &GetNameHash() const;
};



#endif //APP_IR_BUILDER_PACKAGE_H_
