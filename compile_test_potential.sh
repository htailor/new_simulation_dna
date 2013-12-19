#!/bin/sh

clear
echo "Compiling tests...\n"
#g++ -std=c++11 -o test_potential test_potential.cc potential.cc
clang++ -std=c++11 -o test_potential test_potential.cpp potential.cpp
