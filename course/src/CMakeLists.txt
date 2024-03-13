cmake_minimum_required(VERSION 3.27)
project(app)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)

include_directories(/usr/include/antlr4-runtime ./parser)

link_libraries(antlr4-runtime LLVM)

add_executable(app
        main.cpp
        parser/codegen/GoLexer.cpp
        parser/codegen/GoParser.cpp
        parser/codegen/GoParserVisitor.cpp
        parser/codegen/GoParserBaseVisitor.cpp
        parser/GoParserBase.cpp
        ir_builder/ValueWrapper.cpp
        ir_builder/TypeWrapper.cpp
        ir_builder/FunctionWrapper.cpp
        ir_builder/Context.cpp
        ir_builder/ParserVisitor.cpp
        ir_builder/GoIrBuilder.cpp
        ir_builder/GoIrBuilder.h
        ir_builder/Error.cpp
        ir_builder/Error.h)

