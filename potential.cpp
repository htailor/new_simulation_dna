#include <fstream>
#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(){}

Potential::Potential(Nucleation *parameters_, std::string label_)
{
	parameters = parameters_;
	potential_label = label_;
	output_filename = parameters->results_dir + "/" + label_ + "_potential.data";
	
	std::cout << "(Potential) ** base-pair type: " << potential_label << std::endl;
}

double Potential::Value(double eta_)	// The equation of a harmonic potential
{
	return (parameters->sigma/parameters->kappa)*Squared(eta_);
}

std::string Potential::Name()	// Returns the string name of the potential
{
    return potential_label;
}

void Potential::OutputPotentialData()	// Outputs the potential data to a file.
{
	std::ofstream potential_data_file(output_filename.data());
	if(potential_data_file.is_open())
	{
		for(int i = -parameters->m;i<=parameters->m;++i){	// Writes x,y data points for the potential from -m*Delta to m*Delta (from nucleation)
			double eta = i*parameters->delta;				// Points at -L and L can be ignored since it does not affect the shape of the potential
			potential_data_file << eta << "," << Value(eta) << std::endl;
		}		
		potential_data_file.close();
	}
}



