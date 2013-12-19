#include <iostream>
#include <omp.h>
#include "nucleation.hpp"


int main()
{
	const int num_processors = omp_get_max_threads();
	std::cout << "*** Number of parallel processing threads (" << num_processors << ")" << std::endl; 
	omp_set_num_threads(num_processors);




	Nucleation dna_sim(5,10,50,0.1,0.01,2.5,0,5);

	


	
	return 0;
}
