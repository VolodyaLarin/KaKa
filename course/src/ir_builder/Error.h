//
// Created by volodya on 12.03.24.
//

#ifndef APP_ERROR_H
#define APP_ERROR_H


#include <string>
#include <tree/ParseTree.h>

class Error {
public:
    typedef std::shared_ptr<Error> ptr;

private:
    std::string description;

    antlr4::tree::ParseTree *node;

    Error(const std::string &description, antlr4::tree::ParseTree *node);

public:
    static ptr Create(const std::string &description, antlr4::tree::ParseTree *node = nullptr);

    std::string toString();
};


#endif //APP_ERROR_H
