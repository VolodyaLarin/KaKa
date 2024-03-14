# !/bin/bash

set -e

filename=$(basename "$1")
gofmt -w "$1"
echo Build $1
./cmake-build-debug/app main "$1" "./.go-compiler.tmp/$filename.ll" ./builtins.json "./.go-compiler.tmp/$filename.json"
echo Make opt pases
opt "./.go-compiler.tmp/$filename.ll" -passes=simplifycfg,dce,gvn,loop-simplify,mem2reg,sroa,sccp,sink,instcombine,aggressive-instcombine -S -o "./.go-compiler.tmp/$filename.ll"
echo Make object go
llc -filetype=obj "./.go-compiler.tmp/$filename.ll"  --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate -o "./.go-compiler.tmp/$filename.o"
echo Make starter
clang++ -c ./exec_additionals/starter.cpp -o ./.go-compiler.tmp/starter.o -ggdb
echo Prepare executable
clang++ ./.go-compiler.tmp/starter.o "./.go-compiler.tmp/$filename.o" -o "./.go-compiler.tmp/$filename.out"

echo ===
if [[ $2 = "run" ]]
  then ./.go-compiler.tmp/$filename.out
fi