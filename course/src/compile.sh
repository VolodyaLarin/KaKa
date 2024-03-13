# !/bin/bash

set -e

filename=$(basename "$1")

gofmt -w "$1"
echo Build $1
./cmake-build-debug/app "$1"
echo Make opt pases
opt "$1.ll" -passes=simplifycfg,dce,gvn,loop-simplify,mem2reg,sroa,sccp,sink,instcombine,aggressive-instcombine -S -o "./.go-compiller.tmp/$filename.ll"
echo Make object go
llc -filetype=obj "./.go-compiller.tmp/$filename.ll"  --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate -o "./.go-compiller.tmp/$filename.o"
echo Make starter
clang++ -c ./exec_additionals/starter.cpp -o ./.go-compiller.tmp/starter.o -ggdb
echo Prepare executable
clang++ ./.go-compiller.tmp/starter.o "./.go-compiller.tmp/$filename.o" -o "./.go-compiller.tmp/$filename.out"

echo ===
if [[ $2 = "run" ]]
  then ./.go-compiller.tmp/$filename.out
fi