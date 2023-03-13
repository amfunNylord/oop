#include <iostream>
#include <map>

void SaveDictionary(std::ostream& fOut, std::map<std::string, std::string>& dictionary)
{
	for (auto& item : dictionary)
	{
		fOut << item.first << ' ' << item.second << '\n';
	}
}