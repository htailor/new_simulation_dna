#!/bin/sh

clear
echo "Compiling tests...\n"
g++ -I/opt/local/include test_dna.cpp dna.cpp nucleation.cpp mathematical_functions.cpp -o test_dna 
