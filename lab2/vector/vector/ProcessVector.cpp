#include "Vector.h"
#include <iostream>
#include <vector>
#include <algorithm>

void ProcessVector(std::vector<double>& numbers)
{
	if (numbers.empty())
	{
		return;
	}
	auto minMax = std::minmax_element(numbers.begin(), numbers.end());
	double maxElement = *minMax.second;
	double minElement = *minMax.first;
	double multiplicationMaxAndMin = maxElement * minElement;
	// укоротить строчки
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [multiplicationMaxAndMin](double x) { return x < 0 ? x * multiplicationMaxAndMin : x; });
}