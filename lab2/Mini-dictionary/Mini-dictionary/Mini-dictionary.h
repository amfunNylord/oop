#pragma once
#include <map>

void UseDictionary(std::map<std::string, std::string>& dictionary, bool& isSaved);
void ReadDictionary(std::istream& fIn, std::map<std::string, std::string>& dictionary);
void SaveDictionary(std::ostream& fOut, std::map<std::string, std::string>& dictionary);