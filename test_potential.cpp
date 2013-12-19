#include <iostream>
#include <cassert>
#include "potential.hpp"

int main()
{
	double kappa = 10.0;
	double sigma = 2.50;
    
    double eta_b = 2.0;


	Potential *P = new Potential(kappa, sigma, eta_b);

	assert(P->Kappa()==kappa);
   std::cout << "PASSED..." << std::endl;
	assert(P->Sigma()==sigma);
   std::cout << "PASSED..." << std::endl;    
    
    
	return 0;
}
