#include <iostream>
#include <string>
#include <map>
// TryAddWord
void WorkWithUnknownWorld(std::string searchWord, std::string userInput, std::map<std::string, std::string>& dictionaryCopy, bool& isEdit, std::istream& input)
{
	std::cout << "����������� ����� \"" + searchWord + "\". ������� ������� ��� ������ ������ ��� ������.\n";
	getline(input, userInput);
	// is_empty
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