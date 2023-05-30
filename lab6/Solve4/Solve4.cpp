#include "Solve4.h"
#include <math.h>
#include <stdexcept>
#include <iostream>
#include <vector>

// выделить solve2, solve3
// методом ферари решается с 0

const double EQN_EPS = 1e-9;

bool IsZero(double number)
 {
	 return (number > -EQN_EPS && number < EQN_EPS);
 }

double RoundOffNumber(double num)
{
	return round(num * 10000) / 10000;
}

std::vector<float> Solve2(const std::vector<float>& coefs)
{
	// x^2 + px + q = 0
	const auto p = coefs[1] / (2.0f * coefs[2]);
	const auto q = coefs[0] / coefs[2];

	const auto D = p * p - q;
	if (IsZero(D))
	{
		return { -p };
	}
	else if (D < 0)
	{
		return {};
	}

	const auto sqrtD = sqrt(D);

	return { sqrtD - p, -sqrtD - p };
}

std::vector<float> Solve3(const std::vector<float>& coefs)
{
	float A = coefs[2] / coefs[3];
	float B = coefs[1] / coefs[3];
	float C = coefs[0] / coefs[3];

	float sq_A = A * A;
	float p = 1.0 / 3 * (-1.0 / 3 * sq_A + B);
	float q = 1.0 / 2 * (2.0 / 27 * A * sq_A - 1.0 / 3 * A * B + C);

	/* use Cardano's formula */

	float cb_p = p * p * p;
	float D = q * q + cb_p;

	std::vector<float> s;

	if (IsZero(D))
	{
		if (IsZero(q))
		{
			s.push_back(0);
		}
		else
		{
			float u = std::cbrt(-q);
			s.push_back(2 * u);
			s.push_back(-u);
		}
	}
	else /* one real solution */
	{
		float sqrt_D = std::sqrt(D);
		float u = std::cbrt(sqrt_D - q);
		float v = -std::cbrt(sqrt_D + q);

		s.push_back(u + v);
	}

	/* resubstitute */

	float sub = 1.0 / 3 * A;

	for (int i = 0; i < (int)s.size(); ++i)
	{
		s[i] -= sub;
	}

	return s;
}

std::vector<float> Solve4(const std::vector<float>& coefs)
{
	/* normal form: x^4 + Ax^3 + Bx^2 + Cx + D = 0 */

	float A = coefs[3] / coefs[4];
	float B = coefs[2] / coefs[4];
	float C = coefs[1] / coefs[4];
	float D = coefs[0] / coefs[4];

	/*  substitute x = y - A/4 to eliminate cubic term:
		x^4 + px^2 + qx + r = 0 */

	float sq_A = A * A;
	float p = -3.0f / 8.0f * sq_A + B;
	float q = 1.0f / 8.0f * sq_A * A - 1.0f / 2.0f * A * B + C;
	float r = -3.0f / 256.0f * sq_A * sq_A + 1.0f / 16.0f * sq_A * B - 1.0f / 4.0f * A * C + D;
	std::vector<float> s; // TODO: make array()

	if (IsZero(r)) // TODO: coding convension
	{
		/* no absolute term: y(y^3 + py + q) = 0 */

		std::vector<float> coeffs = { q, p, 0, 1 };
		std::vector<float> roots = Solve3(coeffs);

		roots.push_back(0);
		s = roots;
	}
	else
	{
		/* solve the resolvent cubic ... */
		std::vector<float> coeffs = {
			1.0f / 2.0f * r * p - 1.0f / 8.0f * q * q,
			-r,
			-1.0f / 2.0f * p,
			1
		};

		std::vector<float> roots = Solve3(coeffs);

		/* ... and take the one real solution ... */

		float z = roots[0];

		/* ... to build two quadric equations */

		float u = z * z - r;
		float v = 2 * z - p;

		if (IsZero(u))
		{
			u = 0;
		}
		else if (u > 0)
		{
			u = std::sqrt(u);
		}
		else
		{
			return s;
		}

		if (IsZero(v))
		{
			v = 0;
		}
		else if (v > 0)
		{
			v = std::sqrt(v);
		}
		else
		{
			return s;
		}

		coeffs = {
			z - u,
			q < 0 ? -v : v,
			1
		};

		std::vector<float> roots1 = Solve2(coeffs);

		coeffs = {
			z + u,
			q < 0 ? v : -v,
			1
		};

		std::vector<float> roots2 = Solve2(coeffs);

		s.insert(s.end(), roots1.begin(), roots1.end());
		s.insert(s.end(), roots2.begin(), roots2.end());
	}

	/* resubstitute */

	float sub = 1.0 / 4 * A;

	for (int i = 0; i < (int)s.size(); ++i)
	{
		s[i] -= sub;
	}

	return s;
}

//EquationRoot4 Solve4(double a0, double a1, double a2, double a3, double a4)
//{
//	if (a0 == 0)
//	{
//		throw std::invalid_argument("The coefficient at the variable to the fourth degree can't be zero");
//	}
//
//	if (a1 == 0 || a2 == 0 || a3 == 0 || a4 == 0)
//	{
//		throw std::invalid_argument("The coefficients can't be zero");
//	}
//
//	double a = a1 / a0,
//		   b = a2 / a0,
//		   c = a3 / a0,
//		   d = a4 / a0;
//
//	double p = b - 3 * pow(a, 2) / 8,
//		   q = pow(a, 3) / 8 - a * b / 2 + c,
//		   r = -(3 * pow(a, 4) / 256) + pow(a, 2) * b / 16 - c * a / 4 + d;
//
//	double s2 = -p / 2,
//		  s1 = -r,
//		  s0 = (r * p - pow(q, 2) / 4) / 2;
//
//	int negativeS0 = (s0 < 0) ? static_cast<int>(s0) : static_cast<int>(-s0);
//
//	for (int i = negativeS0; i < -s0; i++)
//	{
//		// сравнивать лучше с значением epsilon - const значение для сравнения float 
//		if (fmod(s0, i) == 0.0)
//		{
//			if ((pow(i, 3) + s2 * pow(i, 2) + s1 * i + s0) == 0)
//			{
//				double y1_1 = -(sqrt(2 * i - p));
//				double y0_1 = q / (2 * sqrt(2 * i - p)) + i;
//				double y1_2 = sqrt(2 * i - p);
//				double y0_2 = -(q / (2 * sqrt(2 * i - p))) + i;
//
//				double d1 = pow(y1_1, 2) - 4 * y0_1;
//				double d2 = pow(y1_2, 2) - 4 * y0_2;
//
//				if (d2 < 0 && d1 < 0)
//				{
//					throw std::domain_error("The equation has no valid roots");
//				}
//
//				EquationRoot4 result;
//
//				if (d1 < 0)
//				{
//					result.numRoots = 2;
//					double root3 = (-y1_2 + sqrt(d2)) / 2 - 1;
//					double root4 = (-y1_2 - sqrt(d2)) / 2 - 1;
//					result.roots[0] = RoundOffNumber(root3);
//					result.roots[1] = RoundOffNumber(root4);
//
//				}
//				else if (d2 < 0)
//				{
//					result.numRoots = 2;
//					double root1 = (-y1_1 + sqrt(d1)) / 2 - 1;
//					double root2 = (-y1_1 - sqrt(d1)) / 2 - 1;
//					result.roots[0] = RoundOffNumber(root1);
//					result.roots[1] = RoundOffNumber(root2);
//				}
//				else
//				{
//					double root1 = (-y1_1 + sqrt(d1)) / 2 - 1;
//					double root2 = (-y1_1 - sqrt(d1)) / 2 - 1;
//					double root3 = (-y1_2 + sqrt(d2)) / 2 - 1;
//					double root4 = (-y1_2 - sqrt(d2)) / 2 - 1;
//
//					result.numRoots = 4;
//					result.roots[0] = RoundOffNumber(root1);
//					result.roots[1] = RoundOffNumber(root2);
//					result.roots[2] = RoundOffNumber(root3);
//					result.roots[3] = RoundOffNumber(root4);
//				}
//				return result;
//			}
//		}
//	}
//	throw std::domain_error("The equation has no valid roots");
// }