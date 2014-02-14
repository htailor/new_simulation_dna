#include <iostream>
#include "potential.hpp"
#include "nucleation.hpp"

int main()
{
	Nucleation *test = new Nucleation(5,10,50,1.0,1.0,2.5,0,10);

	Potential *P = new Potential(test,"harmonic");
    P->Name();    
    std::cout << P->Name() << std::endl; 
	P->OutputPotentialData();
	
	for(int i = 0; i<5;i++){
        std::cout << i << "\t" << P->Value(i) << std::endl;
	}


	return 0;
}
