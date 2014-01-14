#!/bin/sh

clear
echo "Compiling tests...\n"
g++ -o test_nucleation test_nucleation.cpp nucleation.cpp
