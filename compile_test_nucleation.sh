#!/bin/sh

clear
echo "Compiling tests...\n"
g++ -std=c++11 -o test_nucleation test_nucleation.cpp nucleation.cpp
