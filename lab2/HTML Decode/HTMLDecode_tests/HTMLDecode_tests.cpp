#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode.h"

SCENARIO("Test ConvertStrToEntities function")
{ 
	WHEN("Input string isn't any matching")
	{
		std::string inputString = "cat";
		THEN("Function returns 'N'");
		{
			char result = ConvertStrToEntities(inputString);
			CHECK(result == 'N');
		}
	}

	WHEN("Input string has quot")
	{
		std::string inputString = "quot";
		THEN("Function returns \"")
		{
			char result = ConvertStrToEntities(inputString);
			CHECK(result == '"');
		}
	}

	WHEN("Input string has matching but not full")
	{
		std::string inputString = "quota";
		THEN("Function returns 'N'")
		{
			char result = ConvertStrToEntities(inputString);
			CHECK(result == 'N');
		}
	}
}

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
}