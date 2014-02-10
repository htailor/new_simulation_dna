#!/bin/sh

clear
echo "Compiling test...\n"
g++ test_transfer_matrix_functions.cpp transfer_matrix_functions.cpp potential.cpp nucleation.cpp mathematical_functions.cpp -o test_transfer_matrix_functions
