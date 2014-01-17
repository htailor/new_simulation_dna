#ifndef _NUCLEATION_
#define _NUCLEATION_

struct Nucleation
{
    int N;
    double L;
    int m;
    double Delta;
    
    double kappa;
    double sigma;
    double kappa_sigma_r;
    double eta_b;
    
    double umin;
    double umax;
    
    Nucleation();
    Nucleation(int N_, double L_, int m_, double kappa_, double sigma_, double eta_b_, double umin_, double umax_);
};


#endif
