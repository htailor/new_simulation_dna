#ifndef _POTENTIAL_
#define _POTENTIAL_

class Potential
{
	public:
		Potential();
		Potential(double kappa_, double sigma_, double eta_b_);
    
		virtual double Value(double x_);
      virtual void DisplayType();
    
      double ETA_B();
		double Kappa();
		double Sigma();

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
