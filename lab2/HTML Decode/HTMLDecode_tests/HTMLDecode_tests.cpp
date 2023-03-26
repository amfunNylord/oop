#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode.h"

SCENARIO("Test Decode function")
{
	WHEN("Input string is empty")
	{
		std::string inputString = "";
		THEN("Decoded string is also empty")
		{
			std::string decodedString = Decode(inputString);
			CHECK(decodedString.empty());
		}
	}
	
	WHEN("Input string has no html-entities")
	{
		std::string inputString = "Test string :)";
		std::string resultString = "Test string :)";
		THEN("Decoded string is the same as input")
		{
			std::string decodedString = Decode(inputString);
			CHECK(decodedString == resultString);
		}
	}

	WHEN("Input string has all html-entities")
	{
		std::string inputString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
		std::string resultString = "Cat <says> \"Meow\". M&M’s";
		THEN("Decoded string is Cat <says> \" Meow \". M&M’s")
		{
			std::string decodedString = Decode(inputString);
			CHECK(decodedString == resultString);
		}
	}

	WHEN("Input string has the form \"&&&&&&&&&&&&&&&&&&&&&&;\"")
	{
		std::string inputString = "&&&&&&&&&&&&&&&&&&&&&&;";
		std::string resultString = "&&&&&&&&&&&&&&&&&&&&&&;";
		THEN("Decoded string is \"&&&&&&&&&&&&&&&&&&&&&&;\"")
		{
			std::string decodedString = Decode(inputString);
			CHECK(decodedString == resultString);
		}
	}
}