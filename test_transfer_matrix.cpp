#include <iostream>
#include "potential.hpp"
#include "transfer_matrix.hpp"

int main()
{
   Nucleation *nuc = new Nucleation(5,5,5,0.1,0.001,2.5,0,10);
    
   Potential test(nuc);
    
   T t_matrix(test);
   T00 t00_matrix(test);
   T11 t11_matrix(test);

   t_matrix.OutputDataMatrix("t_matrix.data");
   t00_matrix.OutputDataMatrix("t00_matrix.data");
   t11_matrix.OutputDataMatrix("t11_matrix.data");
   
   t_matrix.ComputeEigensystem();
   t00_matrix.ComputeEigensystem();
   t11_matrix.ComputeEigensystem();
   
   std::cout << "MAX EVAL (T Matrix) : " << t_matrix.GetEigenSystemMax() << std::endl;
   std::cout << "MAX EVAL (T00 Matrix) : " << t11_matrix.GetEigenSystemMax() << std::endl;
   std::cout << "MAX EVAL (T11 Matrix) : " << t00_matrix.GetEigenSystemMax() << std::endl;
    
   return 0;
}
