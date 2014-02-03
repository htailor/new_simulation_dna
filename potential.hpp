#ifndef _POTENTIAL_
#define _POTENTIAL_

#include <string>
#include <vector>
#include "nucleation.hpp"
#include "data.hpp"

class Potential
{
	public:
		Potential();
		Potential(Nucleation *nucleation_parameters_);
    
		std::string potential_name();

      void DisplayType();
		std::vector<PotentialData> OutputPotentialData();

		virtual double Value(double x_);

		Nucleation getNucleationParameters();
    
	protected:
    
		Nucleation *nucleation_parameters;

		std::string name;

};

class HarmonicPotential: public Potential
{
	public:
      HarmonicPotential(Nucleation *nucleation_parameters_);
		double Value(double x_);
};

class AnharmonicPotential: public Potential
{
	public:
      AnharmonicPotential(Nucleation *nucleation_parameters_);
		double Value(double x_);
};

#endif
