#!/bin/sh

#export OMP_NUM_THREADS=1

clear
echo "Compiling Nucleation..."
g++ -fopenmp -I/opt/local/include main.cpp nucleation.cpp potential.cpp transfer_matrix.cpp transfer_matrix_functions.cpp -o Nucleation -L/opt/local/lib -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
echo "Complete."
