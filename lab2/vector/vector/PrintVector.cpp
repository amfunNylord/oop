#include "Vector.h"

void PrintVector(std::vector<double>& numbers, std::ostream& output)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(output, " "));
}