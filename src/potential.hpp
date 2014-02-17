#ifndef _POTENTIAL_
#define _POTENTIAL_

#include <string>
#include "nucleation.hpp"

class Potential
{
	public:
		
		Potential();
		Potential(Nucleation *parameters_, std::string label_);
		
		double Value(double eta_);
		
		std::string Name();
		void OutputPotentialData();
		
		Nucleation *parameters;
		
	protected:
	
		std::string potential_label;
		std::string output_filename;
};

#endif
