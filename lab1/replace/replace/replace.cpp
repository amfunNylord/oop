#include <fstream>
#include <iostream>
#include <string>

std::string ReplaceString(const std::string& str, const std::string& searchString, const std::string& replaceString)
{
	std::string newStr;
	size_t indexStart = 0, indexEnd = 0;
	if (searchString != "")
	{
		while ((indexStart = str.find(searchString, indexStart)) != std::string::npos)
		{
			newStr.append(str, indexEnd, indexStart - indexEnd);
			indexStart += searchString.length();
			indexEnd = indexStart;
			newStr += replaceString;
		}
	}
	if (indexEnd != str.length())
	{
		newStr.append(str, indexEnd, str.length() - indexEnd);
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
		std::cout << "Problems with input file openning\n";
		return 1;
	}
	if (!outputFile.is_open())
	{
		std::cout << "Problems with output file openning\n";
		return 1;
	}


	std::string searchString = argv[3];
	std::string replaceString = argv[4];

	CopyStrWithReplacement(inputFile, outputFile, searchString, replaceString);

	return 0;
}