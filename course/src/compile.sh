# !/bin/bash

./cmake-build-debug/app
echo Make object go
llc -filetype=obj file.ll   --debugger-tune=gdb --data-sections --debug-entry-values --debug-info-correlate
echo Make starter
gcc -c starter.c -o  starter.o -ggdb
echo link
gcc starter.o file.o