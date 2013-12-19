#!/bin/sh

clear
echo "Compiling tests...\n"
#g++ -std=c++11 -I/opt/local/lib test_dna.cpp dna.cpp nucleation.cpp mathematical_functions.cpp -o test_dna 
g++ -I/opt/local/lib test_dna.cpp dna.cpp nucleation.cpp mathematical_functions.cpp -o test_dna 
