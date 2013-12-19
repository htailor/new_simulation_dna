#!/bin/sh

clear
echo "Compiling tests...\n"
#g++ -std=c++11 -o test_mathematical_functions test_mathematical_functions.cpp mathematical_functions.cpp
clang++ test_mathematical_functions.cpp mathematical_functions.cpp -o test_mathematical_functions
