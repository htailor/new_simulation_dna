#ifndef _DNA_
#define _DNA_

#include <complex>
#include "nucleation.hpp"

class DNA
{
    public:
    
        DNA();
        DNA(Nucleation nucleation_parameters_);
    
        // Analytical solution for the T transfer matrix
    
        double LAMBDA_S(int s_);
        std::complex<double> PSI_S(int s_, double xi_);
    
        // Analytical Solution for T00 transfer matrix when eta goes to infinity

        double LAMBDA_T00_INFINITY(int t_);
        double PSI_T00_INFINITY(int t_, double eta_);
    
    
    private:
    
        Nucleation nucleation_parameters;
    
        double T_ETA_BETA;
        double T_ETA_MU;
        double T_ETA_C;
        double T_ETA_DELTA;
        double T_ETA_B;
        double T_ETA_K;
        double T_ETA_EV0;
        double T_ETA_C0;
};

#endif
