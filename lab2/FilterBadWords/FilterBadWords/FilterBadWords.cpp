#include "FilterBadWords.h"
#include <fstream>

void CheckCommandOptions(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::ifstream fIn(argv[1]);

	}
}

int main()
{
	std::string str;
	while (getline(std::cin, str))
	{
		std::string filteredStr = Filter(str);
		std::cout << filteredStr << '\n';
	}
	return 0;
}
