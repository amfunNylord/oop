#include "stdafx.h"
#include "CarController.h"
#include "Car.h"
// с задней скорости на скорости 20 переключается на вторую +
// не вывело ошибку при движении задам переключение с нейтралки на заднюю +
// при движении задом устанавливаем ту же скорость и меняется направление +
// вывод ошибки +
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
