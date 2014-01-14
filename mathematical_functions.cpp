#include "mathematical_functions.hpp"
//#include <array>

double Factorial(int x_)
{
    static const int precision_limit_n_ = 170;
    
    //static std::array<double, precision_limit_n_+1 > stored_factorials;
    
    static double stored_factorials[precision_limit_n_+1];
    
    static bool init_ = true;
    if(init_)
    {
        init_  = false;
        stored_factorials[0] = 1;
        
        for(int i = 1; i <= precision_limit_n_; i++)
        {
            stored_factorials[i] = stored_factorials[i-1] * i;
        }
        
    }
    
    if(x_ < 0 || x_ > precision_limit_n_)
    {
        std::cout << "*** WARNING FACTORIAL ERROR ***\n- factorial " << x_ << "! out of range (returning 0)" << std::endl;
        return 0;
    }
    
    return stored_factorials[x_];
}
