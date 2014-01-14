#include <iostream>
#include <omp.h>

#include <boost/program_options.hpp>

#include "nucleation.hpp"


int main(int argc, char* argv[])
{
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
		Nucleation sim(vm["N"].as<int>(),
                       vm["L"].as<double>(),
                       vm["m"].as<int>(),
                       vm["kappa"].as<double>(),
                       vm["sigma"].as<double>(),
                       vm["etab"].as<double>(),
                       vm["umin"].as<int>(),
                       vm["umax"].as<int>());
	}
	catch(std::exception& e) {
   	std::cerr << "error: " << e.what() << "\n";
      return 1;
   }
   catch(...) {
      std::cerr << "Exception of unknown type!\n";
   }

	// Detects number of processing cores available
	const int num_processors = omp_get_max_threads();
	std::cout << "*** Number of parallel processing threads (" << num_processors << ")" << std::endl; 
	// Sets number of threads for parallel programming
	omp_set_num_threads(num_processors);


	std::cout << std::endl;
	return 0;
}
