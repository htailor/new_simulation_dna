#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(double kappa_, double sigma_, double eta_b_) : kappa(kappa_), sigma(sigma_), eta_b(eta_b_) {}

double Potential::val_etab()
{
    return eta_b;
}

double Potential::val_kappa()
{
	return kappa;
}

double Potential::val_sigma()
{
	return sigma;
}

double Potential::Value(double x_)
{
    return kappa/sigma;
}

void Potential::DisplayType()
{
    std::cout << "Potential Type: CONSTANT" << std::endl;
}

/// Harmonic Potential ///

HarmonicPotential::HarmonicPotential(double kappa_, double sigma_, double eta_b_) : Potential(kappa_, sigma_, eta_b_) {}

double HarmonicPotential::Value(double x_)
{
	return kappa/sigma*Squared(x_);
}

void HarmonicPotential::DisplayType()
{
    std::cout << "Potential Type: HARMONIC" << std::endl;
}



/// Anharmonic Potential ///

AnharmonicPotential::AnharmonicPotential(double kappa_, double sigma_, double eta_b_) : Potential(kappa_, sigma_, eta_b_) {}

double AnharmonicPotential::Value(double x_)
{
	return kappa/sigma*Sqrt(x_);
}

void AnharmonicPotential::DisplayType()
{
    std::cout << "Potential Type: ANHARMONIC" << std::endl;
}

