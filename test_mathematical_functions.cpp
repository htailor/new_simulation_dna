#include <iostream>
#include <cassert>
#include <typeinfo>
#include "mathematical_functions.hpp"

int main()
{
	//Squared tests
    
   int i = 5;
	int i1 = -5;
	double d = 0.25;

	assert(Squared(i)==25);
   std::cout << "Passed..." << std::endl;

	assert(Squared(d)==0.0625);
   std::cout << "Passed..." << std::endl;

   //Cubed tests

   assert(Cubed(i)==125);
   std::cout << "Passed..." << std::endl;
    
   assert(Cubed(i1)==-125);
   std::cout << "Passed..." << std::endl;
    
	assert(Cubed(d)==0.015625);
   std::cout << "Passed..." << std::endl;

    
   // Factorial tests
    
   int fac_i = 170;
   int fac_i1 = 171;
 
   assert(Factorial(i)==120);
   std::cout << "Passed..." << std::endl;
    
   std::cout << Factorial(fac_i) << std::endl;
   Factorial(fac_i1);

	// Square root
 
   std::cout << Sqrt(i) << std::endl;
   std::cout << Sqrt(i1) << std::endl;

	std::cout << Sqrt((i*d)) << std::endl;

	return 0;
}
