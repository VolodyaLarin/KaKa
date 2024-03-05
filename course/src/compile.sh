# !/bin/bash

set -e

echo Build $1
./cmake-build-debug/app "$1"
echo Make object go
llc -filetype=obj "$1.ll"  --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate -o ./file.o
echo Make starter
gcc -c starter.c -o starter.o -ggdb
echo Prepare executable
gcc starter.o file.o
