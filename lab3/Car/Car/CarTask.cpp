#include "stdafx.h"
#include "CarController.h"
#include "Car.h"

int main()
{
	CCar car;
	CCarController carController(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		if (!carController.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}
	return 0;
}
