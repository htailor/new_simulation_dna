#include <iostream>
#include "nucleation.hpp"

Nucleation::Nucleation(){};

Nucleation::Nucleation(int N_, double L_, int m_, double kappa_, double sigma_, double eta_b_, double umin_, double umax_)
{
    N = N_;
    L = L_;
    m = m_;
    delta = static_cast<double>(L_)/(2*m_+1);
    
    kappa = kappa_;
    sigma = sigma_;
    kappa_sigma_r = kappa_/sigma_;

    eta_b = eta_b_;
    
    umin = umin_; // Units of delta i.e umin = 0*delta, umax = 5*delta
    umax = umax_; //
	
	dimension = 2*m_ + 1;

    results_dir = "./results";
    log_dir = "./log";
    eigen_dir = log_dir + "/eigen";
   
	std::cout << std::endl;
    std::cout << "(Nucleation) Nucleation Parameters " << std::endl;
    std::cout << "(Nucleation) ** N\t\t: " << N << std::endl;
    std::cout << "(Nucleation) ** L\t\t: " << L << std::endl;
    std::cout << "(Nucleation) ** m\t\t: " << m << std::endl;
    std::cout << "(Nucleation) ** delta\t\t: " << delta << std::endl;
    std::cout << "(Nucleation) ** kappa\t\t: " << kappa << std::endl;
    std::cout << "(Nucleation) ** sigma\t\t: " << sigma << std::endl;
    std::cout << "(Nucleation) ** kappa_sigma_r\t: " << kappa_sigma_r << std::endl;
    std::cout << "(Nucleation) ** eta_b\t\t: " << eta_b << std::endl;
    std::cout << "(Nucleation) ** umin\t\t: " << umin << std::endl;
    std::cout << "(Nucleation) ** umax\t\t: " << umax << std::endl;
	std::cout << "(Nucleation) ** dimension\t: " << dimension << std::endl;
	std::cout << std::endl;
}
