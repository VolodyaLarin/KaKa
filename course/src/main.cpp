#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "parser/GoLexer.h"
#include "parser/GoParser.h"
#include "parser/GoParserBaseVisitor.h"

#include "ParserVisitor.h"


void print_tree(antlr4::tree::ParseTree *tree) {

}



using namespace std;
using namespace antlr4;
int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("./file.go");

    ANTLRInputStream input(stream);
    GoLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    GoParser parser(&tokens);
    GoParser::SourceFileContext* tree = parser.sourceFile();
    std::cout << tree->toStringTree(true) << std::endl;

    ParserVisitor visitor;

    visitor.visitSourceFile(tree);

    std::cerr<<"\n";
    std::cerr<<"\n";
    std::cerr<<"\n";


    visitor.context->TheModule->print(llvm::errs(), nullptr);


    std::error_code err;

    auto os = llvm::raw_fd_ostream("./file.ll", err);
    visitor.context->TheModule->print(os, nullptr);

    return 0;
}