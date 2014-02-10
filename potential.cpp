#include <fstream>
#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(Nucleation *nucleation_parameters_) : nucleation_parameters(nucleation_parameters_)
{
	name = "harmonic";
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
			double eta = i*nucleation_parameters->delta;						// Points at -L and L can be ignored since it does not affect the shape of the potential
			potential_data_file << eta << "," << Value(eta) << std::endl;
		}		
		potential_data_file.close();
	}
}

double Potential::Value(double x_)	// The equation of the potential
{
	return (nucleation_parameters->sigma/nucleation_parameters->kappa)*Squared(x_);
}

