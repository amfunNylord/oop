#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Mini-dictionary/Mini-dictionary.h"
#include <sstream>

SCENARIO("Test ReadDictionary function")
{
	WHEN("Input file is empty")
	{
		std::istringstream input("");
		std::map<std::string, std::string> dictionary;
		THEN("Dictionary is also empty")
		{
			ReadDictionary(input, dictionary);
			CHECK(dictionary.empty());
			CHECK(input.eof());
		}
	}

	WHEN("Input file has 1 translation")
	{
		std::istringstream input("cat кошка\n");
		std::map<std::string, std::string> dictionary, result = { { "cat", "кошка" } };
		THEN("Dictionary also has 1 translation")
		{
			ReadDictionary(input, dictionary);
			CHECK(input.eof());
			CHECK(dictionary == result);
		}
	}

	WHEN("Input file has more than 1 translation")
	{
		std::istringstream input("cat кошка\ndog собака\napple €блоко\n");
		std::map<std::string, std::string> dictionary, result = { { "cat", "кошка" }, { "dog", "собака" }, { "apple", "€блоко" } };
		THEN("Dictionary has the same translations")
		{
			ReadDictionary(input, dictionary);
			CHECK(input.eof());
			CHECK(dictionary == result);
		}
	}
}

SCENARIO("Test SaveDictionary function")
{
	WHEN("Dictionary is empty")
	{
		std::map<std::string, std::string> dictionary;
		std::ostringstream output("");
		THEN("Dictionary is also empty")
		{
			SaveDictionary(output, dictionary);
			CHECK(output.str().empty());
		}
	}

	WHEN("Dictionary has one translation")
	{
		std::map<std::string, std::string> dictionary = { { "cat", "кошка" } };
		std::ostringstream output("");
		THEN("Dictionary has the same translation")
		{
			SaveDictionary(output, dictionary);
			CHECK(output.str() == "cat кошка\n");
		}
	}

	WHEN("Dictionary has several translations")
	{
		std::map<std::string, std::string> dictionary = { { "cat", "кошка" }, { "dog", "собака" }, { "apple", "€блоко" } };
		std::ostringstream output;
		THEN("Dictionary has the same translations")
		{
			SaveDictionary(output, dictionary);
			CHECK(output.str() == "apple €блоко\ncat кошка\ndog собака\n");
		}
	}
}