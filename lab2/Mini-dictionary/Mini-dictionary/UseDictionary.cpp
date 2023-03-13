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
				std::cout << "В словарь внесены изменения. Введите Y или y для сохранения перед выходом\n";
				getline(std::cin, userInput);
				if (userInput == "y" || userInput == "Y")
				{
					dictionary = dictionaryCopy;
					isSaved = true;
					std::cout << "Изменения сохранены. До свидания\n";
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
			std::cout << "Неизвестное слово \"" + searchWord + "\". Введите перевод или пустую строку для отказа.\n";	
			getline(std::cin, userInput);
			if (userInput != "" && userInput != "\n")
			{
				dictionaryCopy.insert(std::make_pair(searchWord, userInput));
				std::cout << "Слово \"" + searchWord + "\" сохранено в словаре как \"" + userInput + "\"\n";
				isEdit = true;
			}
			else
			{
				std::cout << "Слово \"" + searchWord + "\" проигнорировано.\n";
			}
		}
		getline(std::cin, userInput);
	}
}