#include <iostream>
#include "nucleation.hpp"
#include "dna.hpp"

int main(){
    
	Nucleation test(5,10,50,2.5,0.1,0.001,0.0,10.0);

	std::cout << test.L << "\t" << test.m << "\t" << test.Delta << "\t" << test.kappa << "\t" << test.sigma << "\t" << test.eta_b << std::endl;

	DNA dna_nucleation(test);

	std::cout << dna_nucleation.LAMBDA_S(0) << std::endl;
    std::cout << dna_nucleation.LAMBDA_S(1) << std::endl;
    std::cout << dna_nucleation.LAMBDA_S(2) << std::endl;
    std::cout << dna_nucleation.LAMBDA_S(3) << std::endl;
    
    std::cout << dna_nucleation.LAMBDA_T(0) << std::endl;
    std::cout << dna_nucleation.LAMBDA_T(1) << std::endl;
    std::cout << dna_nucleation.LAMBDA_T(2) << std::endl;
    std::cout << dna_nucleation.LAMBDA_T(3) << std::endl;
    
	return 0;
}
