#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(double kappa_, double sigma_, double eta_b_) : kappa(kappa_), sigma(sigma_), eta_b(eta_b_)
{
	name = "constant";
}

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

std::string Potential::potential_name()
{
    return name;
}

void Potential::DisplayType()
{
    std::cout << "Potential Type: " << name << std::endl;
}

/// Harmonic Potential ///

HarmonicPotential::HarmonicPotential(double kappa_, double sigma_, double eta_b_) : Potential(kappa_, sigma_, eta_b_)
{
	name = "harmonic";
}

double HarmonicPotential::Value(double x_)
{
	return kappa/sigma*Squared(x_);
}

/// Anharmonic Potential ///

AnharmonicPotential::AnharmonicPotential(double kappa_, double sigma_, double eta_b_) : Potential(kappa_, sigma_, eta_b_)
{
	name = "anharmonic";
}

double AnharmonicPotential::Value(double x_)
{
	return kappa/sigma*Sqrt(x_);
}

