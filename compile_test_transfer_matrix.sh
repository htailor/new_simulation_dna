#!/bin/sh

clear
echo "Compiling test...\n"
g++ -I/opt/local/include test_transfer_matrix.cpp transfer_matrix.cpp transfer_matrix_functions.cpp potential.cpp nucleation.cpp mathematical_functions.cpp -o test_transfer_matrix
