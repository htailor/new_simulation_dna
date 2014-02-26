#include <iostream>
#include <vector>
#include <iterator> 
#include <utility>
#include <iomanip>
#include <fstream>
#include "transfer_matrix.hpp"

#define EVAL_VAL_LIMIT 0.000001

TransferMatrix::TransferMatrix(){}

TransferMatrix::TransferMatrix(Potential p_, std::string label_) : TransferMatrixFunctions(p_)
{
    m = TransferMatrixFunctions::parameters->m;
    delta = TransferMatrixFunctions::parameters->delta;
    dimension = TransferMatrixFunctions::parameters->dimension;

	matrix_label = label_;
	matrix_filename = TransferMatrixFunctions::parameters->log_dir + "/" + label_ + "_matrix.data";
	eval_filename = TransferMatrixFunctions::parameters->log_dir + "/" + label_ + "_eval.data";
	evec_filename = TransferMatrixFunctions::parameters->log_dir + "/" + label_ + "_evec.data";
}

void TransferMatrix::ComputeEigensystem()
{
    Eigen::EigenSolver<Eigen::MatrixXd> eigen(transfer_matrix);
    eval = eigen.eigenvalues().real();
    evec = eigen.eigenvectors().real();

    std::ofstream file(matrix_filename.data());
    if (file.is_open())
    {
        file << transfer_matrix << std::endl;
    }

    std::ofstream eval_file(eval_filename.data());
    if (eval_file.is_open())
    {
        eval_file << eval << std::endl;
    }

    std::ofstream evec_file(evec_filename.data());
    if (evec_file.is_open())
    {
        evec_file << evec << std::endl;
    }
}

std::string TransferMatrix::Label()
{
    return matrix_label;
}

std::vector<std::pair<double,std::vector<double> > > TransferMatrix::GetEigenSystemMax()
{
	return Eigen;
}


int TransferMatrix::OrderEigenSystemMax()
{
    std::cout << std::endl << "(Transfer Matrix) " << matrix_label << " Eigenvalues:" << std::endl;
    int eval_max=0;
    for(int i=0;i<eval.size();i++){
        if(eval(i)>EVAL_VAL_LIMIT){
        
			std::cout << "(Transfer Matrix) ** [" << i << "]\t" << eval(i) << std::endl;
			
			double *pt = evec.col(i).data();
			std::vector<double> Evec(pt,pt+evec.col(i).size());

            std::string evec_filename = TransferMatrixFunctions::parameters->eigen_dir + "/" + matrix_label + "_evec_" + std::to_string(eval_max) + ".data";
            std::ofstream evec_file(evec_filename.data());
            if(evec_file.is_open())
            {
                for(int i=-m;i<=m;i++){
                    evec_file << std::to_string(i*delta) << "," << std::to_string(Evec[i+m]) << "\n";
                }
            }

            std::pair<double, std::vector<double> > eigen_pair (eval(i), Evec);
            Eigen.push_back(eigen_pair);
            eval_max++;
        }
    }
    return Eigen.size();
}

void TransferMatrix::GenerateMatrix()
{
    transfer_matrix.resize(dimension,dimension);
    for(int i=0;i<dimension;++i){
        for(int j=0;j<dimension;++j){
            transfer_matrix(i,j) = delta*function((i-m)*delta,(j-m)*delta);
        }
    }
}

///////////////////////
// Transfer Matrix T //
///////////////////////

T::T(){}

T::T(Potential p_) : TransferMatrix(p_, "T")
{
    GenerateMatrix();
}

double T::function(double ea_, double eb_)
{
    return TransferMatrix::TransferMatrixFunctions::T(ea_, eb_);
}

/////////////////////////
// Transfer Matrix T00 //
/////////////////////////

T00::T00(){}

T00::T00(Potential p_) : TransferMatrix(p_, "T00")
{
    GenerateMatrix();
}

double T00::function(double ea_, double eb_)
{
    return TransferMatrix::TransferMatrixFunctions::T_hat00(ea_, eb_);
}

/////////////////////////
// Transfer Matrix T11 //
/////////////////////////

T11::T11(){}

T11::T11(Potential p_) : TransferMatrix(p_, "T11")
{
    GenerateMatrix();
}

double T11::function(double ea_, double eb_)
{
    return TransferMatrix::TransferMatrixFunctions::T_hat11(ea_, eb_);
}
