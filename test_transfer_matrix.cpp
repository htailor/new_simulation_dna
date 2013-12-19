#include <iostream>
#include "potential.hpp"
#include "transfer_matrix.hpp"

int main()
{
    Potential test(0.1,0.001,2.5);
    
    TransferMatrix TM_dna(test);
    
    std::cout << TM_dna.T(0,1) << std::endl;
    std::cout << TM_dna.T_hat(0,1) << std::endl;


    
    return 0;
}
