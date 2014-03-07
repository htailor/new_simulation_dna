#ifndef _TRANSFER_MATRIX_
#define _TRANSFER_MATRIX_

#include <string>
#include <vector>
#include <Eigen/Dense>
#include "transfer_matrix_functions.hpp"

class TransferMatrix
{
    public:
        TransferMatrix();
        TransferMatrix(Potential &p_, std::string label_);
        
        virtual double function(double ea_, double eb_) const = 0;
        std::string Label() const;
        
		void ComputeEigensystem();
        int OrderEigenSystemMax();
        std::vector<std::pair<double,std::vector<double> > > GetEigenSystemMax();
        
        ~TransferMatrix();
       
    protected:
        void GenerateMatrix();        
		
		const Nucleation m_parameters;
		const TransferMatrixFunctions *m_tm_functions;
        const int m_m = m_parameters.m;
        const int m_dimension = m_parameters.dimension;
        const double m_delta = m_parameters.delta;
        
        const std::string m_matrix_label;
		const std::string m_matrix_filename = m_parameters.log_dir + "/" + m_matrix_label + "_matrix.data";
		const std::string m_eval_filename = m_parameters.log_dir + "/" + m_matrix_label + "_eval.data";
		const std::string m_evec_filename = m_parameters.log_dir + "/" + m_matrix_label + "_evec.data";
        
        Eigen::MatrixXd m_transfer_matrix;
        Eigen::MatrixXd m_evec;
        Eigen::VectorXd m_eval;
        
        std::vector<std::pair<double, std::vector<double> > > m_Eigen;
};


class T : public TransferMatrix
{
    public:
        T();
        T(Potential &p_);
        
        double function(double ea_, double eb_) const;
        
        ~T();
};

class T00 : public TransferMatrix
{
    public:
        T00();
        T00(Potential &p_);
        
        double function(double ea_, double eb_) const;
        
        ~T00();
};

class T11 : public TransferMatrix
{
    public:
        T11();
        T11(Potential &p_);
        
        double function(double ea_, double eb_) const;
        
        ~T11();
};

#endif
