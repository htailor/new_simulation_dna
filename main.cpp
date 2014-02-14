#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "nucleation.hpp"
#include "potential.hpp"
#include "transfer_matrix.hpp"


void CleanOutputData(std::string dir){
    boost::filesystem::path data_dir(dir);
    if(boost::filesystem::exists(data_dir)){
        std::cout << "--> Clearing old " << dir << " data..." << std::endl;
        boost::filesystem::remove_all(data_dir);
    }
    boost::filesystem::create_directory(data_dir);
    std::cout << "--> Complete." << std::endl;
}


int main(int argc, char* argv[])
{	
	Nucleation *parameters;

	try{
	    boost::program_options::options_description desc("Nucleation required parameters");
		desc.add_options()
			("N", boost::program_options::value<int>()->required(), "Length of the biomolecule (nodes)")
			("L", boost::program_options::value<double>()->required(), "Length of dimensionless space eta")
			("m", boost::program_options::value<int>()->required(), "Number of discrete intervals across eta")
			("kappa", boost::program_options::value<double>()->required(), "Backbone spring constant")
			("sigma", boost::program_options::value<double>()->required(), "Base-pair spring constant")
			("etab", boost::program_options::value<double>()->required(), "Set eta_b limit")
			("umin", boost::program_options::value<int>()->required(), "Minimum extension value")
			("umax", boost::program_options::value<int>()->required(), "Maximum extension value")
		;

		boost::program_options::variables_map vm;
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc),vm);
		
		// Test whether any arguments have been passed, print help otherwise
		if(vm.empty()==true){
			std::cout << desc << std::endl;
			return 0;
		}

		// Test all required parameters have been passed on the cmd line, throws exception if not
		boost::program_options::notify(vm);

		// Create object containing the nucleation parameters from cmdline (through BOOST vm)
	    parameters = new Nucleation(vm["N"].as<int>(),
									vm["L"].as<double>(),
                       				vm["m"].as<int>(),
                       				vm["kappa"].as<double>(),
                       				vm["sigma"].as<double>(),
                       				vm["etab"].as<double>(),
                       				vm["umin"].as<int>(),
                       				vm["umax"].as<int>());
	}
	catch(std::exception& e){
   	    std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
    }
    
    //////////////////////// 
	// Setup Calculations //
	//////////////////////// 

    // Clear old data
    std::cout << "--> Results directory: " << parameters->results_dir << std::endl;
    CleanOutputData(parameters->results_dir); 
    std::cout << "--> Log directory: " << parameters->log_dir << std::endl;
    CleanOutputData(parameters->log_dir); 
	std::cout << "--> Eigensystem directory: " << parameters->eigen_dir << std::endl;
	CleanOutputData(parameters->eigen_dir); 

	// Detects number of processing cores available
	const int num_processors = omp_get_max_threads();
	std::cout << std::endl << "*** Number of parallel processing threads (" << num_processors << ")" << std::endl << std::endl; 
	// Sets number of threads for parallel programming
	omp_set_num_threads(num_processors);


	/////////////////////////////////// 
	// Initialize Nucleation Objects //
	/////////////////////////////////// 

	std::cout << "--> Initialising pair potential..." << std::endl;
	Potential pair_potential(parameters,"harmonic");
    pair_potential.OutputPotentialData();
	std::cout << "--> Complete." << std::endl << std::endl;
	
	std::cout << "--> Initialising transfer matrix functions..." << std::endl;
	TransferMatrixFunctions functions(pair_potential);
	std::cout << "--> Complete." << std::endl << std::endl;
	
	std::cout << "--> Initialising T, T00, T11 transfer matrices, calculating eigenvalues and eigenvectors..." << std::endl;
    T t_matrix(pair_potential);
    T00 t00_matrix(pair_potential);
    T11 t11_matrix(pair_potential);

    #pragma omp parallel sections 
    {
	    #pragma omp section
        {
            t_matrix.ComputeEigensystem();
            std::cout << "--> Transfer Matrix " << t_matrix.Label() << " Complete." << std::endl;
        }
        #pragma omp section
        {
            t00_matrix.ComputeEigensystem();
            std::cout << "--> Transfer Matrix " << t00_matrix.Label() << " Complete." << std::endl;
        }
        #pragma omp section
        {
            t11_matrix.ComputeEigensystem();
            std::cout << "--> Transfer Matrix " << t11_matrix.Label() << " Complete." << std::endl;
        }
    }

   	const int smax = t_matrix.OrderEigenSystemMax();
   	const int tmax = t00_matrix.OrderEigenSystemMax();
	const int vmax = t11_matrix.OrderEigenSystemMax();
    
   	std::cout << std::endl << "--> MAX EVAL (T Matrix)\t\t: " << smax << std::endl;
   	std::cout << "--> MAX EVAL (T00 Matrix)\t: " << tmax << std::endl;
   	std::cout << "--> MAX EVAL (T11 Matrix)\t: " << vmax << std::endl << std::endl;
   	
   	
   	
	return 0;
}
