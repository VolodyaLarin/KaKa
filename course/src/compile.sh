# !/bin/bash

set -e

filename=$(basename "$1")

gofmt -w "$1"
echo Build $1
./cmake-build-debug/app "$1"
echo Make object go
llc -filetype=obj "$1.ll"  --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate -o ./.go-compiller.tmp/$filename.o
echo Make starter
clang++ -c ./exec_additionals/starter.cpp -o ./.go-compiller.tmp/starter.o -ggdb
echo Prepare executable
clang++ ./.go-compiller.tmp/starter.o ./.go-compiller.tmp/$filename.o -o ./.go-compiller.tmp/$filename.out

echo ===

./.go-compiller.tmp/$filename.out