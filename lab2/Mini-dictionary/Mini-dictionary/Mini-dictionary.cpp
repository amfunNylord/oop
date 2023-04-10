#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "Mini-dictionary.h"
#include "Windows.h"
//check argc
// �������� readdictionary �� � ���� �������
void CheckCommandOptions(int argc, char* argv[], bool& isInputFileGood, std::map<std::string, std::string> dictionary)
{
	if (argc == 2)
	{
		std::ifstream fIn(argv[1]);
		if (fIn.is_open())
		{
			isInputFileGood = true;
			ReadDictionary(fIn, dictionary);
			fIn.close(); // ����� �� ���������
		}
		else
		{
			std::cout << "���� �� �������� �� ����� ���� ������, ���������� ������ �������\n";
		}
	}
}
// �� ������ �����
void SaveFile(bool isInputFileGood, std::map<std::string, std::string> dictionary, char* argv[], std::istream& input)
{
	std::string outputFileName;
	if (!isInputFileGood)
	{
		std::cout << "������� ��� �����, � ������� �� ������ ��������� �������\n";
		getline(input, outputFileName);
	}
	else
	{
		outputFileName = argv[1];
	}
	std::ofstream fOut(outputFileName);
	SaveDictionary(fOut, dictionary);
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������� � ��������� ���
	std::map<std::string, std::string> dictionary;

	bool isInputFileGood = false;
	CheckCommandOptions(argc, argv, isInputFileGood, dictionary);

	std::cout << "������� �����, ������� ������ ���������\n";

	bool isSaved = false;
	UseDictionary(dictionary, isSaved, std::cin);
	// isNeededToSave
	if (isSaved)
	{
		SaveFile(isInputFileGood, dictionary, argv, std::cin);
	}
}