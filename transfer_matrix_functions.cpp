#include <cmath>
#include "mathematical_functions.hpp"
#include "transfer_matrix_functions.hpp"

TransferMatrixFunctions::TransferMatrixFunctions(){}

TransferMatrixFunctions::TransferMatrixFunctions(Potential p_)
{
    potential = p_;
    parameters = potential.getNucleationParameters();
}

double TransferMatrixFunctions::potential_test(double eta_)
{
	return potential.Value(eta_);
}

double TransferMatrixFunctions::g0(double eta_)
{
    double _g0;
    if(std::abs(eta_) < parameters.eta_b){
        _g0 = 1;
    }
    else{
        _g0 = 0;
    }
    return _g0;
}

double TransferMatrixFunctions::g1(double eta_)
{
    double _g1;
    if(std::abs(eta_) < parameters.eta_b){
        _g1 = 0;
    }
    else{
        _g1 = 1;
    }
    return _g1;
}

double TransferMatrixFunctions::T(double ea_, double eb_)
{
    return exp(-Squared(ea_-eb_));
}

double TransferMatrixFunctions::T_hat(double na_, double nb_)
{
    return exp(-Squared(na_-nb_))*exp(-(potential.Value(na_) + potential.Value(nb_))/2);
}

double TransferMatrixFunctions::T_hat00(double na_, double nb_)
{
    return g0(na_)*g0(nb_)*T_hat(na_,nb_);
}

double TransferMatrixFunctions::T_hat01(double na_, double nb_)
{
    return g0(na_)*g1(nb_)*T_hat(na_,nb_);
}

double TransferMatrixFunctions::T_hat10(double na_, double nb_)
{
    return g1(na_)*g0(nb_)*T_hat(na_,nb_);
}

double TransferMatrixFunctions::T_hat11(double na_, double nb_)
{
    return g1(na_)*g1(nb_)*T_hat(na_,nb_);
}
