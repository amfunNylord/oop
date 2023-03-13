#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "Mini-dictionary.h"
#include "Windows.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, std::string> dictionary;

	bool isInputFileGood = false;

	if (argc == 2)
	{
		std::ifstream fIn(argv[1]);
		if (fIn.is_open())
		{
			isInputFileGood = true;
			ReadDictionary(fIn, dictionary);
			fIn.close();
		}
		else
		{
			std::cout << "Файл со словарем не может быть открыт, используем пустой словарь\n";
		}
	}
	std::cout << "Введите слово, которое хотите перевети\n";

	bool isSaved = false;
	UseDictionary(dictionary, isSaved);

	if (isSaved && isInputFileGood)
	{
		std::ofstream fOut(argv[1]);
		if (fOut.is_open())
		{
			SaveDictionary(fOut, dictionary);
		}
		else
		{
			std::cout << "Файл нельзя открыть, словарь не сохранен\n";
		}
	}
}