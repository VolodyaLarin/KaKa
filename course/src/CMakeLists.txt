cmake_minimum_required(VERSION 3.27)
project(app)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)

include_directories(/usr/include/antlr4-runtime)

link_libraries(antlr4-runtime LLVM)

add_executable(app main.cpp ./parser/GoLexer.cpp ./parser/GoParser.cpp ./parser/GoParserVisitor.cpp ./parser/GoParserBaseVisitor.cpp ./parser/GoParserBase.cpp
        ParserVisitor.h)

