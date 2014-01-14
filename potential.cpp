#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(double kappa_, double sigma_, double eta_b_)
{
    kappa = kappa_;
    sigma = sigma_;

    eta_b = eta_b_;
}

double Potential::Value(double x_)
{
    return kappa/sigma;
}

void Potential::DisplayType()
{
    std::cout << "Potential Type: CONSTANT" << std::endl;
}

double Potential::ETA_B()
{
    return eta_b;
}

double Potential::Kappa()
{
	return kappa;
}

double Potential::Sigma()
{
	return sigma;
}


/// Harmonic Potential ///

HarmonicPotential::HarmonicPotential(double kappa_, double sigma_, double eta_b_)
{
    kappa = kappa_;
    sigma = sigma_;
    
    eta_b = eta_b_;
}

double HarmonicPotential::Value(double x_)
{
	return kappa/sigma*Squared(x_);
}

void HarmonicPotential::DisplayType()
{
    std::cout << "Potential Type: HARMONIC" << std::endl;
}



/// Anharmonic Potential ///

AnharmonicPotential::AnharmonicPotential(double kappa_, double sigma_, double eta_b_)
{
    kappa = kappa_;
    sigma = sigma_;
    
    eta_b = eta_b_;
}

double AnharmonicPotential::Value(double x_)
{
	return kappa/sigma*Sqrt(x_);
}

void AnharmonicPotential::DisplayType()
{
    std::cout << "Potential Type: ANHARMONIC" << std::endl;
}

