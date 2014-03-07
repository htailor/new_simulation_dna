#ifndef _POTENTIAL_
#define _POTENTIAL_

#include <string>
#include "nucleation.hpp"

class Potential
{
	public:
		Potential(const Nucleation &parameters_);		// Nucleation object should be read only	
		
		void OutputPotentialData() const;
		std::string Name() const;
		Nucleation Parameters() const;
		
		virtual double Value(double eta_) const = 0;	// Pure virtual function => Potential is now an abstract class
		virtual ~Potential();
		
	protected:
		const Nucleation m_parameters;					// parameters cannot be changed
		std::string m_potential_label;
		std::string m_output_filename;
};

class HarmonicPotential : public Potential
{
	public:
		HarmonicPotential(const Nucleation &parameters_);
		double Value(double eta_) const;
		~HarmonicPotential();
};

#endif
