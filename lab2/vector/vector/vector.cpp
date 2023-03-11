#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
/*Умножить каждый отрицательный элемент массива на произведение максимального и минимального элементов исходного массива*/

int main()
{
	std::vector<double> numbers;

	ReadVector(numbers, std::cin);

	ProcessVector(numbers);

	std::sort(numbers.begin(), numbers.end());

	PrintVector(numbers, std::cout);
}
