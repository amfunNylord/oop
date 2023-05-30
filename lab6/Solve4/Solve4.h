#pragma once
#include <vector>

struct EquationRoot4
{
	double numRoots;
	double roots[4];
};

//EquationRoot4 Solve4(double a1, double a2, double a3, double a4, double a5);
std::vector<float> Solve4(const std::vector<float>& coefs);