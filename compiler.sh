#!/bin/bash
# this is the compiler for cpp files that includes ncurses.h library
# it takes in one argument (cppname) from user input

cppname=$1
outname=${cppname%.*}
outname=$outname".o"
g++ -pedantic-errors -std=c++11 $cppname -o $outname -lncurses
./$outname