#include "stdafx.h"
#include "Solve4.h"
#include <vector>

int main()
{
	std::cout << "Enter the coefficients of a 4th degree equation: ";
	float a0, a1, a2, a3, a4;
	std::cin >> a0 >> a1 >> a2 >> a3 >> a4;
	std::vector<float> coefs = {a4, a3, a2, a1, a0};
	Solve4(coefs);
	/*EquationRoot4 rootResult;
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
	}*/
	std::cout << std::endl;
    return 0;
}
