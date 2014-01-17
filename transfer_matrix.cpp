#include <cmath>
#include "mathematical_functions.hpp"
#include "transfer_matrix.hpp"

TransferMatrix::TransferMatrix(){}

TransferMatrix::TransferMatrix(Potential p_)
{
    transfer_matrix_potential = p_;
}

double TransferMatrix::g0(double eta_)
{
    double _g0;
    if(std::abs(eta_) <= transfer_matrix_potential.ETA_B()){
        _g0 = 1;
    }
    else{
        _g0 = 0;
    }
    return _g0;
}

double TransferMatrix::g1(double eta_)
{
    double _g1;
    if(std::abs(eta_) <= transfer_matrix_potential.ETA_B()){
        _g1 = 0;
    }
    else{
        _g1 = 1;
    }
    return _g1;
}



double TransferMatrix::T(double ea_, double eb_)
{
    return exp(-Squared(ea_-eb_));
}

double TransferMatrix::T_hat(double na_, double nb_)
{
    return exp(-Squared(na_-nb_))*exp(-(transfer_matrix_potential.Value(na_) + transfer_matrix_potential.Value(nb_))/2);
}

double TransferMatrix::T_hat00(double na_, double nb_)
{
    return g0(na_)*g0(nb_)*T_hat(na_,nb_);
}

double TransferMatrix::T_hat01(double na_, double nb_)
{
    return g0(na_)*g1(nb_)*T_hat(na_,nb_);
}

double TransferMatrix::T_hat10(double na_, double nb_)
{
    return g1(na_)*g0(nb_)*T_hat(na_,nb_);
}

double TransferMatrix::T_hat11(double na_, double nb_)
{
    return g1(na_)*g1(nb_)*T_hat(na_,nb_);
}


