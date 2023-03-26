#include <iostream>
#include <string>
#include <map>
#include "Mini-dictionary.h"

void UseDictionary(std::map<std::string, std::string>& dictionary, bool& isSaved, std::istream& input)
{
	std::map<std::string, std::string> dictionaryCopy = dictionary;
	bool isEdit = false;
	std::string userInput;
	getline(input, userInput);
	while (1)
	{
		if (input.eof())
		{
			return;
		}
		if (userInput == "...")
		{
			if (isEdit == true)
			{
				SaveChanges(userInput, dictionary, dictionaryCopy, isSaved, input);
			}
			break;
		}
		std::string searchWord = userInput;
		bool isFound = false;
		if (!dictionaryCopy.empty())
		{
			FindTranslation(userInput, dictionaryCopy, isFound);
		}
		if (isFound == false)
		{
			WorkWithUnknownWorld(searchWord, userInput, dictionaryCopy, isEdit, input);
		}
		getline(input, userInput);
	}
}