#include <iostream>
#include <fstream>
#include <map>
// ReadDictionaryFromFile
void ReadDictionary(std::istream& fIn, std::map<std::string, std::string>& dictionary)
{
	std::string enWord, ruWord;
	while (fIn >> enWord && fIn >> ruWord)
	{
		dictionary.insert(std::make_pair(enWord, ruWord));
	}
}