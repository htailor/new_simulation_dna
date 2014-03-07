#include <iostream>
#include "potential.hpp"
#include "transfer_matrix_functions.hpp"

int main()
{
    Nucleation nuc(5,10,50,1.,1.,2.5,0,10);
    
    Harmonic pe(nuc);
    TransferMatrixFunctions TM(pe);

    std::cout << TM.T(0,1) << std::endl;
    std::cout << TM.T_hat(0,1) << std::endl;
    
    return 0;
}
