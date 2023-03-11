#include <fstream>
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> dictionary;

void Dictionary()
{
	std::string userInput;
	do
	{
		getline(std::cin, userInput);
		std::map<std::string, std::string>::iterator it = dictionary.find(userInput);
		if (it != dictionary.end())
		{
			std::cout << it->second << '\n';
		}
		else
		{
			std::cout << "Неизвестное слово \"" + it->second + "\". Введите перевод или пустую строку для отказа.\n";
			getline(std::cin, userInput);
		}
	} while (userInput != "...");
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream fIn(argv[1]);
		if (fIn.is_open())
		{
			std::string enWord, ruWord;
			while (fIn >> enWord && fIn >> ruWord)
			{
				dictionary.insert(std::make_pair(enWord, ruWord));
			}
		}
		else
		{
			std::cout << "Файл со словарем не может быть открыт, используем пустой словарь\n";
		}
	}

	Dictionary();
}