#include <iostream>
#include <cassert>
#include "potential.hpp"

int main()
{
	double kappa = 10.0;
	double sigma = 2.50;
    
   double eta_b = 2.0;


	Potential *P = new Potential(kappa, sigma, eta_b);

	assert(P->val_kappa()==kappa);
   std::cout << "PASSED..." << std::endl;
	assert(P->val_sigma()==sigma);
   std::cout << "PASSED..." << std::endl;    
   P->DisplayType();    
   

	double hkappa = 20;
	double hsigma = 5.0;
	double heta_b = 4.0;

	Potential *H = new HarmonicPotential(hkappa, hsigma, heta_b);   

	assert(H->val_kappa()==hkappa);
   std::cout << "PASSED..." << std::endl;
	assert(H->val_sigma()==hsigma);
   std::cout << "PASSED..." << std::endl;    
   H->DisplayType();    
 
	return 0;
}
