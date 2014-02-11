#include <iostream>
#include <vector>
#include <omp.h>
#include <Eigen/Dense>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "nucleation.hpp"
#include "potential.hpp"
#include "transfer_matrix.hpp"


void CleanOutputData(const char *dir){
    boost::filesystem::path results_dir(dir);
    if(boost::filesystem::exists(results_dir)){
        std::cout << "--> Clearing old " << dir << " data..." << std::endl;
        boost::filesystem::remove_all(results_dir);
    }
    boost::filesystem::create_directory(results_dir);
    std::cout << "--> Complete." << std::endl;
}





int main(int argc, char* argv[])
{	
	Nucleation *nuc_para;

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
	    nuc_para = new Nucleation(vm["N"].as<int>(),
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
    std::cout << "--> Results directory: " << nuc_para->results_dir << std::endl;
    CleanOutputData(nuc_para->results_dir); 
    std::cout << "--> Log directory: " << nuc_para->log_dir << std::endl;
    CleanOutputData(nuc_para->log_dir); 

    return 0;
	// Detects number of processing cores available
	const int num_processors = omp_get_max_threads();
	std::cout << std::endl << "*** Number of parallel processing threads (" << num_processors << ")" << std::endl << std::endl; 
	// Sets number of threads for parallel programming
	omp_set_num_threads(num_processors);


	/////////////////////////////////// 
	// Initialize Nucleation Objects //
	/////////////////////////////////// 

	std::cout << "--> Initialising pair potential..." << std::endl;
	Potential pair_potential(nuc_para);
	pair_potential.DisplayType();
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
            t_matrix.OutputData();
            std::cout << "--> Transfer Matrix " << t_matrix.Label() << " Complete." << std::endl;
        }
        #pragma omp section
        {
            t00_matrix.ComputeEigensystem();
            t00_matrix.OutputData();
            std::cout << "--> Transfer Matrix " << t00_matrix.Label() << " Complete." << std::endl;
        }
        #pragma omp section
        {
            t11_matrix.ComputeEigensystem();
            t11_matrix.OutputData();
            std::cout << "--> Transfer Matrix " << t11_matrix.Label() << " Complete." << std::endl;
        }
    }

   	const int smax = t_matrix.GetEigenSystemMax();
   	const int tmax = t00_matrix.GetEigenSystemMax();
	const int vmax = t11_matrix.GetEigenSystemMax();
    
   	std::cout << std::endl << "--> MAX EVAL (T Matrix) : " << smax << std::endl;
   	std::cout << "--> MAX EVAL (T00 Matrix) : " << tmax << std::endl;
   	std::cout << "--> MAX EVAL (T11 Matrix) : " << vmax << std::endl << std::endl;
	
	
	
	
	






	return 0;
}
