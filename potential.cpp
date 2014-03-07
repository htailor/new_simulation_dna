#include <fstream>
#include "potential.hpp"
#include "mathematical_functions.hpp"

Potential::Potential(const Nucleation &parameters_) : m_parameters(parameters_){}

void Potential::OutputPotentialData() const														// Outputs the potential data to a file.
{
	std::ofstream potential_data_file(m_output_filename.data());								// writes to ./results
	if(potential_data_file.is_open()){
		for(int i = -m_parameters.m;i<=m_parameters.m;++i){										// Writes x,y data points for the potential from -m*Delta to m*Delta (from nucleation)
			double eta = i*m_parameters.delta;													// Points at -L and L can be ignored since it does not affect the shape of the potential
			potential_data_file << eta << "," << Value(eta) << std::endl;
		}		
	}
    potential_data_file.close();
}

std::string Potential::Name() const																// Returns the string name of the potential
{
    return m_potential_label;
}

Nucleation Potential::Parameters() const
{
	return m_parameters;
}

Potential::~Potential(){}

HarmonicPotential::HarmonicPotential(const Nucleation &parameters_) : Potential(parameters_)
{
	m_potential_label = "harmonic";
	m_output_filename = m_parameters.results_dir + "/" + m_potential_label + "_potential.data";
	std::cout << "(Potential) ** base-pair type: " << m_potential_label << std::endl;
}

double HarmonicPotential::Value(double eta_)	const														// The equation of a harmonic potential
{
	return (m_parameters.sigma/m_parameters.kappa)*Squared(eta_);
}

HarmonicPotential::~HarmonicPotential(){}