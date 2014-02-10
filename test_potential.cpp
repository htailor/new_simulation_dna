#include <iostream>
#include <cassert>

#include "potential.hpp"
#include "nucleation.hpp"

int main()
{

	Nucleation *test = new Nucleation(5,10,50,0.1,0.001,2.5,0,10);


	Potential *P = new Potential(test);
   P->DisplayType();    
   std::cout << P->potential_name() << std::endl; 
	P->OutputPotentialData();

	Potential *H = new HarmonicPotential(test);   
   H->DisplayType();    
   std::cout << H->potential_name() << std::endl; 
	H->OutputPotentialData();


	return 0;
}
