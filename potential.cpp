#include <fstream>
#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(Nucleation *nucleation_parameters_) : nucleation_parameters(nucleation_parameters_)
{
	name = "constant";
}

Nucleation Potential::getNucleationParameters()
{
	return *nucleation_parameters;
}

std::string Potential::potential_name()	// Returns the string name of the potential
{
    return name;
}

void Potential::DisplayType()		// Prints the name of the potential
{
    std::cout << "(Potential) ** Potential Type: " << potential_name() << std::endl;
}

void Potential::OutputPotentialData()	// Outputs the potential data to a file.
{
	std::string data_filename = "potential_" + potential_name() + ".data";	// Specifies the filename to be created

	std::ofstream potential_data_file(data_filename.data());
	if(potential_data_file.is_open())
	{
		for(int i = -nucleation_parameters->m;i<=nucleation_parameters->m;++i){	// Writes x,y data points for the potential from -m*Delta to m*Delta (from nucleation)
			double xData = i*nucleation_parameters->Delta;								// Points at -L and L can be ignored since it does not affect the shape of the potential
			double yData = Value(xData);
			potential_data_file << xData << "," << yData << std::endl;
		}		
		potential_data_file.close();
	}
}

double Potential::Value(double x_)	// The equation of the potential
{
    return nucleation_parameters->kappa/nucleation_parameters->sigma;
}

/// Harmonic Potential ///

HarmonicPotential::HarmonicPotential(Nucleation *nucleation_parameters_) : Potential(nucleation_parameters_)
{
	name = "harmonic";
}

double HarmonicPotential::Value(double x_)
{
	return nucleation_parameters->kappa/nucleation_parameters->sigma*Squared(x_);
}

/// Anharmonic Potential ///

AnharmonicPotential::AnharmonicPotential(Nucleation *nucleation_parameters_) : Potential(nucleation_parameters_)
{
	name = "anharmonic";
}

double AnharmonicPotential::Value(double x_)
{
	return nucleation_parameters->kappa/nucleation_parameters->sigma*Sqrt(x_);
}

