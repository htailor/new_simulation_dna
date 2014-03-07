#include <iostream>
#include "potential.hpp"
#include "transfer_matrix.hpp"

int main()
{
   Nucleation nuc(5,10,50,1.,1.,2.5,0,10);
    
   Harmonic test(nuc);
    
   T t_matrix(test);
   T00 t00_matrix(test);
   T11 t11_matrix(test);

   //t_matrix.OutputDataMatrix("t_matrix.data");
   //t00_matrix.OutputDataMatrix("t00_matrix.data");
   //t11_matrix.OutputDataMatrix("t11_matrix.data");
   
   t_matrix.ComputeEigensystem();
   t00_matrix.ComputeEigensystem();
   t11_matrix.ComputeEigensystem();
   
   std::cout << "MAX EVAL (T Matrix) : " << t_matrix.OrderEigenSystemMax() << std::endl;
   std::cout << "MAX EVAL (T00 Matrix) : " << t00_matrix.OrderEigenSystemMax() << std::endl;
   std::cout << "MAX EVAL (T11 Matrix) : " << t11_matrix.OrderEigenSystemMax() << std::endl;
    
   return 0;
}
