#!/bin/sh

clear
echo "Compiling test...\n"
g++ test_transfer_matrix.cpp transfer_matrix.cpp potential.cpp mathematical_functions.cpp -o test_transfer_matrix
