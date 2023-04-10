#include <iostream>
#include <map>
// лучше не исспользовать вывод консоль в данной функции
// должно возвращать слово
void FindTranslation(std::string userInput, std::map<std::string, std::string> dictionaryCopy, bool& isFound)
{
	auto searchPair = dictionaryCopy.find(userInput);
	if (searchPair != dictionaryCopy.end())
	{
		isFound = true;
		std::cout << searchPair->second << '\n';
	}
}