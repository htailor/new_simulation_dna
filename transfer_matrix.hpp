#ifndef _TRANSFER_MATRIX_
#define _TRANSFER_MATRIX_

#include "potential.hpp"

class TransferMatrix
{
    public:
    
        TransferMatrix();
    
        TransferMatrix(Potential p_);
    
    
        double T(double ea_, double eb_);
    
        double T_hat(double na_, double nb_);
    
        double T_hat00(double na_, double nb_);
    
        double T_hat01(double na_, double nb_);
    
        double T_hat10(double na_, double nb_);
    
        double T_hat11(double na_, double nb_);
    
    
    private:
    
        double g0(double eta_);
    
        double g1(double eta_);
    
        Potential transfer_matrix_potential;
    
};

#endif
