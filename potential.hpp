#ifndef _POTENTIAL_
#define _POTENTIAL_

class Potential
{
	public:
		Potential();
		Potential(double kappa_, double sigma_, double eta_b_);
    
      double val_etab();
		double val_kappa();
		double val_sigma();

      virtual void DisplayType();
		virtual double Value(double x_);
    
	protected:
    
		double kappa;
		double sigma;
      double eta_b;
};

class HarmonicPotential: public Potential
{
	public:
      HarmonicPotential(double kappa_, double sigma_, double eta_b_);
		double Value(double x_);
      void DisplayType();
};

class AnharmonicPotential: public Potential
{
	public:
      AnharmonicPotential(double kappa_, double sigma_, double eta_b_);
		double Value(double x_);
      void DisplayType();
};

#endif
