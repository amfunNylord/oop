#include "stdafx.h"
#include "Solve4.h"

int main()
{
	std::cout << "Enter the coefficients of a 4th degree equation: ";
	double a0, a1, a2, a3, a4;
	std::cin >> a0 >> a1 >> a2 >> a3 >> a4;
	EquationRoot4 rootResult;
	try
	{
		rootResult = Solve4(a0, a1, a2, a3, a4);
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	std::cout << "The roots are ";
	for (int i = 0; i < rootResult.numRoots; i++)
	{
		std::cout <<std::setprecision(5) << rootResult.roots[i] << ' ';
	}
	std::cout << std::endl;
    return 0;
}
