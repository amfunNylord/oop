#include "Vector.h"
#include <iostream>
#include <vector>

void ReadVector(std::vector<double>& numbers, std::istream& input)
{
	double number;
	while (input >> number)
	{
		numbers.push_back(number);
	}
}