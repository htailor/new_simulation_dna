#ifndef _MATHEMATICAL_FUNCTIONS_
#define _MATHEMATICAL_FUNCTIONS_

#include <cmath>
#include <iostream>

template<typename T> 
inline T Squared(T x_)
{
	return x_*x_;
}

template<typename T> 
inline T Cubed(T x_)
{
	return x_*x_*x_;
}

template<typename T>
inline double Sqrt(T x_)
{
	try
	{
		if(x_ < 0)
		{
			throw x_;
		}
	}
	catch(T e)
	{
		std::cout << "*** WARNING SQURE-ROOT ERROR ***\n- taking the square root of a negative number " << e << " (returning 0)" << std::endl;
		return 0;
	}
	return sqrt(x_);
}

double Factorial(int x_);

#endif
