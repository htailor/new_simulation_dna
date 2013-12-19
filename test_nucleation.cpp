#include <iostream>
#include "nucleation.hpp"

int main(){
    
	Nucleation test(5,10,50,0.1,0.001,2.5,0,10);

	std::cout << test.L << "\t" << test.m << "\t" << test.Delta << "\t" << test.kappa << "\t" << test.sigma << "\t" << test.eta_b << std::endl;

    
    Nucleation test2;
    
    test2.L = 5;
    test2.m = 10;
    test2.Delta = (double)test2.L/(2*test2.m +1);
    test2.eta_b = 2.5;
    
	std::cout << test2.L << "\t" << test2.m << "\t" << test2.Delta << "\t" << test2.eta_b << std::endl;

    
	return 0;
}
