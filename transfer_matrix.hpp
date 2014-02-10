#ifndef _TRANSFER_MATRIX_
#define _TRANSFER_MATRIX_

#include <string>
#include <Eigen/Dense>
#include "transfer_matrix_functions.hpp"

class TransferMatrix : public TransferMatrixFunctions
{

    public:
        
        void OutputData();
		void ComputeEigensystem();
        int GetEigenSystemMax();
        std::string Label();
       
    protected:
 
        TransferMatrix();
        TransferMatrix(Potential p_, std::string label_);
        
        void GenerateMatrix();        
        virtual double function(double ea_, double eb_){};
    
        int m;
        int dimension;
        double delta;

		std::string matrix_label;
		std::string matrix_filename;
		std::string eval_filename;
		std::string evec_filename;
        
        Eigen::MatrixXd transfer_matrix;
        Eigen::MatrixXd evec;
        Eigen::VectorXd eval;
};


class T : public TransferMatrix
{
    public:
    
        T();
        T(Potential p_);
        
        double function(double ea_, double eb_);
};

class T00 : public TransferMatrix
{
    public:
    
        T00();
        T00(Potential p_);
        
        double function(double ea_, double eb_);
};

class T11 : public TransferMatrix
{
    public:
    
        T11();
        T11(Potential p_);
        
        double function(double ea_, double eb_);
};

#endif
