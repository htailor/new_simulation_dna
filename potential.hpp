#ifndef _POTENTIAL_
#define _POTENTIAL_

#include <string>

class Potential
{
	public:
		Potential();
		Potential(double kappa_, double sigma_, double eta_b_);
    
      double val_etab();
		double val_kappa();
		double val_sigma();

		std::string potential_name();

      void DisplayType();

		virtual double Value(double x_);
    
	protected:
    
		double kappa;
		double sigma;
      double eta_b;

		std::string name;

};

class HarmonicPotential: public Potential
{
	public:
      HarmonicPotential(double kappa_, double sigma_, double eta_b_);
		double Value(double x_);
};

class AnharmonicPotential: public Potential
{
	public:
      AnharmonicPotential(double kappa_, double sigma_, double eta_b_);
		double Value(double x_);
};

#endif
