#include "Solve4.h"
#include <math.h>
#include <stdexcept>
#include <iostream>

 // выделить solve2, solve3
// методом ферари решается с 0

double RoundOffNumber(double num)
{
	return round(num * 10000) / 10000;
}

EquationRoot4 Solve4(double a0, double a1, double a2, double a3, double a4)
{
	if (a0 == 0)
	{
		throw std::invalid_argument("The coefficient at the variable to the fourth degree can't be zero");
	}

	if (a1 == 0 || a2 == 0 || a3 == 0 || a4 == 0)
	{
		throw std::invalid_argument("The coefficients can't be zero");
	}

	double a = a1 / a0,
		   b = a2 / a0,
		   c = a3 / a0,
		   d = a4 / a0;

	double p = b - 3 * pow(a, 2) / 8,
		   q = pow(a, 3) / 8 - a * b / 2 + c,
		   r = -(3 * pow(a, 4) / 256) + pow(a, 2) * b / 16 - c * a / 4 + d;

	double s2 = -p / 2,
		  s1 = -r,
		  s0 = (r * p - pow(q, 2) / 4) / 2;

	int negativeS0 = (s0 < 0) ? static_cast<int>(s0) : static_cast<int>(-s0);

	for (int i = negativeS0; i < -s0; i++)
	{
		// сравнивать лучше с значением epsilon - const значение для сравнения float 
		if (fmod(s0, i) == 0.0)
		{
			if ((pow(i, 3) + s2 * pow(i, 2) + s1 * i + s0) == 0)
			{
				double y1_1 = -(sqrt(2 * i - p));
				double y0_1 = q / (2 * sqrt(2 * i - p)) + i;
				double y1_2 = sqrt(2 * i - p);
				double y0_2 = -(q / (2 * sqrt(2 * i - p))) + i;

				double d1 = pow(y1_1, 2) - 4 * y0_1;
				double d2 = pow(y1_2, 2) - 4 * y0_2;

				if (d2 < 0 && d1 < 0)
				{
					throw std::domain_error("The equation has no valid roots");
				}

				EquationRoot4 result;

				if (d1 < 0)
				{
					result.numRoots = 2;
					double root3 = (-y1_2 + sqrt(d2)) / 2 - 1;
					double root4 = (-y1_2 - sqrt(d2)) / 2 - 1;
					result.roots[0] = RoundOffNumber(root3);
					result.roots[1] = RoundOffNumber(root4);

				}
				else if (d2 < 0)
				{
					result.numRoots = 2;
					double root1 = (-y1_1 + sqrt(d1)) / 2 - 1;
					double root2 = (-y1_1 - sqrt(d1)) / 2 - 1;
					result.roots[0] = RoundOffNumber(root1);
					result.roots[1] = RoundOffNumber(root2);
				}
				else
				{
					double root1 = (-y1_1 + sqrt(d1)) / 2 - 1;
					double root2 = (-y1_1 - sqrt(d1)) / 2 - 1;
					double root3 = (-y1_2 + sqrt(d2)) / 2 - 1;
					double root4 = (-y1_2 - sqrt(d2)) / 2 - 1;

					result.numRoots = 4;
					result.roots[0] = RoundOffNumber(root1);
					result.roots[1] = RoundOffNumber(root2);
					result.roots[2] = RoundOffNumber(root3);
					result.roots[3] = RoundOffNumber(root4);
				}
				return result;
			}
		}
	}
	throw std::domain_error("The equation has no valid roots");
 }