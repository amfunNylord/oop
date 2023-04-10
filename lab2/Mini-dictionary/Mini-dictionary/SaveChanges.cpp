#include <iostream>
#include <string>
#include <map>
// убрать dictionarycopy 
void SaveChanges(std::string userInput, std::map<std::string, std::string>& dictionary, std::map<std::string, std::string> dictionaryCopy, bool& isSaved, std::istream& input)
{
	std::cout << "¬ словарь внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом\n";
	getline(input, userInput);
	if (userInput == "y" || userInput == "Y")
	{
		dictionary = dictionaryCopy;
		isSaved = true;
	}
}