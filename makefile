CC  = g++
CFLAGS=-c

all: Nucleation

Nucleation: main.o nucleation.o potential.o transfer_matrix_functions.o transfer_matrix.o
        $(CC) main.o nucleation.o potential.o transfer_matrix_functions.o transfer_matrix.o -o Nucleation

nucleation.o:   nucleation.cpp
        $(CC) $(CFLAGS) nucleation.cpp

potential.o:    potential.cpp
        $(CC) $(CFLAGS) potential.cpp
                
transfer_matrix_functions.o:    transfer_matrix_functions.cpp
        $(CC) $(CFLAGS) transfer_matrix_functions.cpp

transfer_matrix.o:   transfer_matrix.cpp
        $(CC) $(CFLAGS) transfer_matrix.cpp
                

clean: 
        rm -rf *.o Nucleation




 
clear
g++ -std=c++11 -fopenmp -I/opt/local/include main.cpp nucleation.cpp potential.cpp transfer_matrix.cpp transfer_matrix_functions.cpp -o Nucleation -L/opt/local/lib -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
