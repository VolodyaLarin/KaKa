//
// Created by volodya on 12.03.24.
//

#include "Error.h"

Error::Error(const std::string &description, antlr4::tree::ParseTree *node) : description(description), node(node) {}

std::string Error::toString() {
  auto str = description;
  if (node) {
    str += ":" + node->getText();
  }
  return "\n=======\n"  + str + "\n=======\n" ;
}

Error::ptr Error::Create(const std::string &description, antlr4::tree::ParseTree *node) {
  auto err = std::make_shared<Error>(Error(description, node));
  std::cerr << err->toString() << std::endl;
  return err;
}
