#include <iostream>
#include <string>
#include <map>

void SaveChanges(std::string userInput, std::map<std::string, std::string>& dictionary, std::map<std::string, std::string> dictionaryCopy, bool& isSaved, std::istream& input)
{
	std::cout << "� ������� ������� ���������. ������� Y ��� y ��� ���������� ����� �������\n";
	getline(input, userInput);
	if (userInput == "y" || userInput == "Y")
	{
		dictionary = dictionaryCopy;
		isSaved = true;
	}
}