#include <iostream>
#include "potential.hpp"
#include "nucleation.hpp"

void function(Potential *P){
	for(int i = 0; i<5;i++){
        std::cout << i << "\t" << P->Value(i) << std::endl;
	}
}

int main()
{
	Nucleation *test = new Nucleation(5,10,50,1.0,1.0,2.5,0,10);

	Potential *P = new HarmonicPotential(*test);
	
    P->Name();    
    std::cout << P->Name() << std::endl; 
	P->OutputPotentialData();
	
	function(P);
	
	return 0;
}
