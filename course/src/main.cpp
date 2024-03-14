#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "parser/codegen/GoLexer.h"
#include "parser/codegen/GoParser.h"
#include "parser/codegen/GoParserBaseVisitor.h"

#include "ir_builder/ParserVisitor.h"
#include "loader/PackageJson.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;
using namespace antlr4;

int main(int argc, const char *argv[]) {

    if (argc <= 5) {
        std::cerr << "compiler moduleName filenameIn.go filenameOut.ll packageDecl.in.json packageDecl.out.json" << std::endl;
        return -1;
    }

  std::string moduleName = argv[1];
  std::string filename = argv[2];
  std::string filenameOut = argv[3];
  std::string packageDeclIn = argv[4];
  std::string packageDeclOut = argv[5];

  auto irBuilder = std::make_shared<GoIrBuilder>();

  TypeWrapper::SetContext(irBuilder->GetContext().TheContext.get());


  PackagesDetails packages_details = {};
  {
    std::ifstream iPackage;
    iPackage.open(packageDeclIn);
    auto importer = PackageJson(&iPackage, irBuilder->GetContext().TheContext.get());
    packages_details = importer.Import();
  }

  std::ifstream stream;
  stream.open(filename);
  ANTLRInputStream input(stream);
  GoLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  GoParser parser(&tokens);
  GoParser::SourceFileContext *tree = parser.sourceFile();

  Package cur = {moduleName,  moduleName};
  irBuilder->setPackageDetails(cur, packages_details.packages);

  ParserVisitor visitor(irBuilder);
  tree->accept(&visitor);

  std::error_code err;
  auto os = llvm::raw_fd_ostream(filenameOut, err);
  irBuilder->GetContext().TheModule->print(os, nullptr);
  if (err) {
    return err.value();
  }


  auto curPack =irBuilder->GetContext().currentPackage;

  packages_details.packages.insert({moduleName, curPack});

  std::ofstream jsonExportStream(packageDeclOut);
  auto exporter = PackageJson(&jsonExportStream);
  exporter.Export(packages_details);
}