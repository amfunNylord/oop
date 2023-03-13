#include <iostream>
#include <string>
#include <map>

void UseDictionary(std::map<std::string, std::string>& dictionary, bool& isSaved)
{
	std::map<std::string, std::string> dictionaryCopy = dictionary;
	bool isEdit = false;
	std::string userInput;
	getline(std::cin, userInput);
	while (1)
	{
		if (userInput == "...")
		{
			if (isEdit == true)
			{
				std::cout << "� ������� ������� ���������. ������� Y ��� y ��� ���������� ����� �������\n";
				getline(std::cin, userInput);
				if (userInput == "y" || userInput == "Y")
				{
					dictionary = dictionaryCopy;
					isSaved = true;
					std::cout << "��������� ���������. �� ��������\n";
				}
			}
			break;
		}
		std::string searchWord = userInput;
		bool isFound = false;
		if (!dictionaryCopy.empty())
		{
			auto searchPair = dictionaryCopy.find(userInput);
			if (searchPair != dictionaryCopy.end())
			{
				isFound = true;
				std::cout << searchPair->second << '\n';
			}
		}
		if (isFound == false)
		{
			std::cout << "����������� ����� \"" + searchWord + "\". ������� ������� ��� ������ ������ ��� ������.\n";	
			getline(std::cin, userInput);
			if (userInput != "" && userInput != "\n")
			{
				dictionaryCopy.insert(std::make_pair(searchWord, userInput));
				std::cout << "����� \"" + searchWord + "\" ��������� � ������� ��� \"" + userInput + "\"\n";
				isEdit = true;
			}
			else
			{
				std::cout << "����� \"" + searchWord + "\" ���������������.\n";
			}
		}
		getline(std::cin, userInput);
	}
}