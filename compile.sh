#!/bin/sh

#export OMP_NUM_THREADS=1

clear
echo "Compiling Nucleation..."
g++ -fopenmp -I/opt/local/include main.cpp nucleation.cpp -o Nucleation -L/opt/local/lib -lboost_program_options-mt
echo "Complete."
