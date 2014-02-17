#ifndef _TRANSFER_MATRIX_FUNCTIONS_
#define _TRANSFER_MATRIX_FUNCTIONS_

#include "potential.hpp"
#include "nucleation.hpp"

class TransferMatrixFunctions
{
    public:
    
      TransferMatrixFunctions();
        
      TransferMatrixFunctions(Potential p_);
     
      double T(double ea_, double eb_);
        
      double T_hat(double na_, double nb_);
        
      double T_hat00(double na_, double nb_);
        
      double T_hat01(double na_, double nb_);
    
      double T_hat10(double na_, double nb_);
    
      double T_hat11(double na_, double nb_);

    
    protected:
    
      double g0(double eta_);
    
      double g1(double eta_);
    
      Potential potential;
        
      Nucleation *parameters; 
};

#endif
