#include <cmath>
#include <iostream>

#include <boost/math/special_functions/hermite.hpp>
#include <boost/math/special_functions/factorials.hpp>

#include "mathematical_functions.hpp"
#include "dna.hpp"

DNA::DNA(){}

DNA::DNA(Nucleation nucleation_values_) : T_ETA_BETA(4)
{
    dna_nucleation_values = nucleation_values_;
    
    T_ETA_BETA = 4;
    
    T_ETA_MU = T_ETA_BETA/dna_nucleation_values.kappa_sigma_r;
    
    T_ETA_C = 0.5*Sqrt(Squared(T_ETA_MU)+2*T_ETA_BETA*T_ETA_MU);
    
    T_ETA_DELTA = 2*T_ETA_C + T_ETA_MU + T_ETA_BETA;
    
    T_ETA_B = 0.5*Sqrt((Squared(T_ETA_DELTA)-Squared(T_ETA_BETA))/T_ETA_DELTA);
    
    T_ETA_K = log(T_ETA_DELTA/T_ETA_BETA);
    
    T_ETA_EV0 = Sqrt(4*M_PI/T_ETA_DELTA);
    
    T_ETA_C0 = 0.5*pow(M_PI/T_ETA_C,-0.25);
    
    std::cout << "(DNA) DNA Analytical Parameters " << std::endl;
    std::cout << "(DNA) ** T_ETA_BETA\t: " << T_ETA_BETA << std::endl;
    std::cout << "(DNA) ** T_ETA_MU\t: " << T_ETA_MU << std::endl;
    std::cout << "(DNA) ** T_ETA_C\t: " << T_ETA_C << std::endl;
    std::cout << "(DNA) ** T_ETA_DELTA\t: " << T_ETA_DELTA << std::endl;
    std::cout << "(DNA) ** T_ETA_B\t: " << T_ETA_B << std::endl;
    std::cout << "(DNA) ** T_ETA_K\t: " << T_ETA_K << std::endl;
    std::cout << "(DNA) ** T_ETA_EV0\t: " << T_ETA_EV0 << std::endl;
    std::cout << "(DNA) ** T_ETA_C0\t: " << T_ETA_C0 << std::endl;
    
}

// Analytical eigenvalue and eigenvector solutions to the DNA backbone transfer matrix

double DNA::LAMBDA_S(int s_)
{
    return Sqrt(M_PI)*exp(-Squared(M_PI*s_/dna_nucleation_values.L));
}

std::complex<double> DNA::PSI_S(int s_, double xi_)
{
	return std::polar(1/Sqrt(dna_nucleation_values.L),s_*xi_*2*M_PI/dna_nucleation_values.L);
}

// Analytical eigenvalue and eigenvector solutions to the DNA intact base-pair transfer matrix in the limit of eta going to inifty.

double DNA::LAMBDA_T(int t_)
{
    return T_ETA_EV0*exp(-T_ETA_K*t_);
}

double DNA::PSI_T(int t_, double eta_)
{
    //using namespace boost::math;
    
    //return 2*T_ETA_C0*Sqrt(1/pow(2,t_)*factorial<double>(t_))*exp(-0.5*T_ETA_C*Squared(eta_))*hermite(t_,T_ETA_B*eta_);
    //return 2*T_ETA_C0*Sqrt(1/pow(2,t_)*factorial<double>(t_))*exp(-0.5*T_ETA_C*Squared(eta_));//*hermite(t_,T_ETA_B*eta_);

	 return boost::math::factorial<double>(2);
}
















