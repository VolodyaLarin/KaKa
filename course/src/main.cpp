#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "parser/codegen/GoLexer.h"
#include "parser/codegen/GoParser.h"
#include "parser/codegen/GoParserBaseVisitor.h"

#include "ir_builder/ParserVisitor.h"


void print_tree(antlr4::tree::ParseTree *tree) {

}


using namespace std;
using namespace antlr4;

int main(int argc, const char *argv[]) {

    if (argc < 2) {
        std::cerr << "No file name" << std::endl;
        return -1;
    }

    for (size_t i = 1; i < argc; i++) {
        std::ifstream stream;
        stream.open(argv[i]);
        ANTLRInputStream input(stream);
        GoLexer lexer(&input);
        CommonTokenStream tokens(&lexer);

        GoParser parser(&tokens);
        GoParser::SourceFileContext *tree = parser.sourceFile();


        ParserVisitor visitor;
        tree->accept(&visitor);

        std::string newfilename = argv[i];
        newfilename += ".ll";

        std::error_code err;
        auto os = llvm::raw_fd_ostream(newfilename, err);
        visitor.GetGoIrBuilder()->GetContext().TheModule->print(os, nullptr);

        if (err) {
            return err.value();
        }

    }
    return 0;
}