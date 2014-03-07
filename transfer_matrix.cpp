#include <iostream>
#include <vector>
#include <iterator> 
#include <utility>
#include <iomanip>
#include <fstream>
#include "transfer_matrix.hpp"

#define EVAL_VAL_LIMIT 0.000001

TransferMatrix::TransferMatrix(){}

TransferMatrix::TransferMatrix(Potential &p_, std::string label_) : m_parameters(p_.Parameters()), m_matrix_label(label_)
{
	m_tm_functions = new TransferMatrixFunctions(p_);
}

std::string TransferMatrix::Label() const
{
    return m_matrix_label;
}

void TransferMatrix::GenerateMatrix()
{
    m_transfer_matrix.resize(m_dimension, m_dimension);
    for(int i=0;i<m_dimension;++i){
        for(int j=0;j<m_dimension;++j){
            m_transfer_matrix(i,j) = m_delta*function((i-m_m)*m_delta,(j-m_m)*m_delta);
        }
    }
}

void TransferMatrix::ComputeEigensystem()
{
    Eigen::EigenSolver<Eigen::MatrixXd> eigen(m_transfer_matrix);
    m_eval = eigen.eigenvalues().real();
    m_evec = eigen.eigenvectors().real();

    std::ofstream matrix_file(m_matrix_filename.data());
    if (matrix_file.is_open())
    {
        matrix_file << m_transfer_matrix << std::endl;
    }

    std::ofstream eval_file(m_eval_filename.data());
    if (eval_file.is_open())
    {
        eval_file << m_eval << std::endl;
    }

    std::ofstream evec_file(m_evec_filename.data());
    if (evec_file.is_open())
    {
        evec_file << m_evec << std::endl;
    }
}

std::vector<std::pair<double,std::vector<double> > > TransferMatrix::GetEigenSystemMax()
{
	return m_Eigen;
}

int TransferMatrix::OrderEigenSystemMax()
{
    std::cout << std::endl << "(Transfer Matrix) " << m_matrix_label << " Eigenvalues:" << std::endl;
    int eval_max=0;
    for(int i=0;i<m_eval.size();i++){
        if(m_eval(i)>EVAL_VAL_LIMIT){
			std::cout << "(Transfer Matrix) ** [" << i << "]\t" << m_eval(i) << std::endl;
			
			double *pt = m_evec.col(i).data();
			std::vector<double> Evec(pt,pt+m_evec.col(i).size());

            std::string filename = m_parameters.eigen_dir + "/" + m_matrix_label + "_evec_" + std::to_string(eval_max) + ".data";
            std::ofstream evec_file(filename.data());
            if(evec_file.is_open())
            {
                for(int i=-m_m;i<=m_m;i++){
                    evec_file << std::to_string(i*m_delta) << "," << std::to_string(Evec[i+m_m]) << "\n";
                }
            }
            std::pair<double, std::vector<double> > eigen_pair (m_eval(i), Evec);
            m_Eigen.push_back(eigen_pair);
            eval_max++;
        }
    }
    return m_Eigen.size();
}

TransferMatrix::~TransferMatrix(){}

///////////////////////
// Transfer Matrix T //
///////////////////////

T::T(){}

T::T(Potential &p_) : TransferMatrix(p_, "T")
{
    GenerateMatrix();
}

double T::function(double ea_, double eb_) const
{
    return m_tm_functions->T(ea_, eb_);
}

T::~T(){}

/////////////////////////
// Transfer Matrix T00 //
/////////////////////////

T00::T00(){}

T00::T00(Potential &p_) : TransferMatrix(p_, "T00")
{
    GenerateMatrix();
}

double T00::function(double ea_, double eb_) const
{
    return m_tm_functions->T_hat00(ea_, eb_);
}

T00::~T00(){}

/////////////////////////
// Transfer Matrix T11 //
/////////////////////////

T11::T11(){}

T11::T11(Potential &p_) : TransferMatrix(p_, "T11")
{
    GenerateMatrix();
}

double T11::function(double ea_, double eb_) const
{
    return m_tm_functions->T_hat11(ea_, eb_);
}

T11::~T11(){}