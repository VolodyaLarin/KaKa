# !/bin/bash

set -e

gofmt -w "$1"
echo Build $1
./cmake-build-debug/app "$1"
echo Make object go
llc -filetype=obj "$1.ll"  --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate -o ./file.o
echo Make starter
clang++ -c starter.cpp -o starter.o -ggdb
echo Prepare executable
clang++ starter.o file.o
echo ========
#./a.out

