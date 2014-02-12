#ifndef _NUCLEATION_
#define _NUCLEATION_

#include <string>

struct Nucleation
{
	Nucleation();
    Nucleation(int N_, double L_, int m_, double kappa_, double sigma_, double eta_b_, double umin_, double umax_);
	
    int N;
    double L;
    int m;
    double delta;
    
    double kappa;
    double sigma;
    double kappa_sigma_r;
    double eta_b;
    
    double umin;
    double umax;
    
	int dimension;

    std::string results_dir;
    std::string log_dir;
};


#endif
