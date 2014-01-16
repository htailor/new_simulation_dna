#!/bin/sh

clear
echo "Compiling tests...\n"
g++ test_potential.cpp potential.cpp nucleation.cpp -o test_potential
