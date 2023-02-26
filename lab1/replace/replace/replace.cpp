#include <fstream>
#include <iostream>
#include <string>

void CopyPartOfStr(size_t& i, size_t lim, std::string& newStr, std::string str)
{
	for (i; i < lim; i++)
	{
		newStr += str[i];
	}
}

std::string ReplaceString(const std::string& str, const std::string& searchString, const std::string& replaceString)
{
	std::string newStr;
	size_t indexOfSearchString = 0, indexOfAllString = 0;
	if (searchString != "")
	{
		while ((indexOfSearchString = str.find(searchString, indexOfSearchString)) != std::string::npos)
		{
			CopyPartOfStr(indexOfAllString, indexOfSearchString, newStr, str);
			indexOfSearchString += searchString.length();
			indexOfAllString = indexOfSearchString;
			newStr += replaceString;
		}
	}
	if (indexOfAllString != str.length())
	{
		CopyPartOfStr(indexOfAllString, str.length(), newStr, str);
	}
	return newStr;
}

void CopyStrWithReplacement(std::istream& inputFile, std::ostream& outputFile, const std::string& searchString, const std::string& replaceString)
{
	std::string str;
	
	while (getline(inputFile, str))
	{
		outputFile << ReplaceString(str, searchString, replaceString) << '\n';
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid argument count\nUsage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	std::ofstream outputFile(argv[2]);

	if (!inputFile.is_open())
	{
		std::cout << "Problems with file openning\n";
		return 1;
	}

	std::string searchString = argv[3];
	std::string replaceString = argv[4];

	CopyStrWithReplacement(inputFile, outputFile, searchString, replaceString);

	return 0;
}