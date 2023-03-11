// vector_tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../vector/Vector.h"

SCENARIO("Test ReadVector function")
{
	WHEN("Input stream is empty")
	{
		std::vector<double> numbers;
		std::istringstream input("");
		THEN("Vector is also empty")
		{
			ReadVector(numbers, input);
			CHECK(numbers.empty());
			CHECK(input.eof());
		}
	}

	WHEN("Input stream has 1 number")
	{
		std::vector<double> numbers;
		std::istringstream input("1.23");
		THEN("Vector also has 1 number")
		{
			ReadVector(numbers, input);
			CHECK(numbers.size() == 1);
			CHECK(input.eof());
		}
	}

	WHEN("Input stream has more than 1 number")
	{
		std::vector<double> numbers;
		std::istringstream input("1.23 43.12 -23.23");
		THEN("Vector also has the same count of numbers as in input stream")
		{
			ReadVector(numbers, input);
			CHECK(numbers.size() == 3);
			CHECK(input.eof());
		}
	}
}

SCENARIO("Test PrintVector function")
{
	WHEN("Vector is empty")
	{
		std::vector<double> numbers;
		std::ostringstream output;
		THEN("Output stream is also empty")
		{
			PrintVector(numbers, output);
			CHECK(output.str().empty());
		}
	}

	WHEN("Vector has 1 number")
	{
		std::vector<double> numbers = { 1.23 };
		std::ostringstream output;
		THEN("Output stream also has 1 number")
		{
			PrintVector(numbers, output);
			CHECK(output.str() == "1.23 ");
		}
	}

	WHEN("Vector has more than 1 number")
	{
		std::vector<double> numbers = { 1.23, -2.42, 5.2 };
		std::ostringstream output;
		THEN("Output stream also has more than 1 number")
		{
			PrintVector(numbers, output);
			CHECK(output.str() == "1.23 -2.42 5.2 ");
		}
	}
}

SCENARIO("Test ProcessVector function")
{
	WHEN("Vector is empty")
	{
		std::vector<double> numbers;
		std::vector<double> result;
		THEN("Result vector also is empty")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}

	WHEN("Vector has 1 positive number")
	{
		std::vector<double> numbers = { 1.2 };
		std::vector<double> result = { 1.2 };
		THEN("Result vector has also the same number")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}

	WHEN("Vector has more than 1 only positive numbers")
	{
		std::vector<double> numbers = { 1.2, 2.3, 0.5 };
		std::vector<double> result = { 1.2, 2.3, 0.5 };
		THEN("Result vector has also the same number")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}

	WHEN("Vector has 1 negative number")
	{
		std::vector<double> numbers = { -1.2 };
		std::vector<double> result = { -1.728 };
		THEN("Result vector has number multiplied on smallest and biggest number of vector")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}

	
	WHEN("Vector has more than 1 only negative number")
	{
		std::vector<double> numbers = { -1, -5, -10 };
		std::vector<double> result = { -10, -50, -100 };
		THEN("Result vector has number multiplied on smallest and biggest number of vector")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}

	WHEN("Vector has more than 1 numbers, they are as positive and negative numbers")
	{
		std::vector<double> numbers = { 1, -5, 10, -6, 21, 50 };
		std::vector<double> result = { 1, 1500, 10, 1800, 21, 50 };
		THEN("Result vector has number multiplied on smallest and biggest number of vector")
		{
			ProcessVector(numbers);
			CHECK(result == numbers);
		}
	}
}