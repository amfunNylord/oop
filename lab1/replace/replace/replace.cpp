#include <fstream>
#include <iostream>
#include <string>

void ReadRemainingPartOfStr(int& i, int lim, std::string& newStr, std::string str)
{
	for (i; i < lim; i++)
	{
		newStr += str[i];
	}
}

int main(int argc, char* argv[])
{
	if (argv[1] == NULL)
	{
		std::cout << "Input filename is empty\n";
		return -1;
	}
	if (argv[2] == NULL)
	{
		std::cout << "Output filename is empty\n";
		return -1;
	}

	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);
	std::string str;
	if (argc > 4)
	{
		std::string searchString = argv[3];
		std::string replaceString = argv[4];

		while (getline(inputFile, str))
		{
			std::string newStr;
			int index = 0, i = 0;
			while ((index = str.find(searchString, index)) != std::string::npos)
			{
				ReadRemainingPartOfStr(i, index, newStr, str);
				index += searchString.length();
				i = index;
				newStr += replaceString;
			}
			if (i != str.length())
			{
				ReadRemainingPartOfStr(i, str.length(), newStr, str);
			}
			outputFile << newStr << '\n';
		}
	}
	else
	{
		while (getline(inputFile, str))
		{
			outputFile << str << '\n';
		}	
	}
	return 0;
}
