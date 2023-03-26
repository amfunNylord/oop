#pragma once
#include <map>

void UseDictionary(std::map<std::string, std::string>& dictionary, bool& isSaved, std::istream& input);
void ReadDictionary(std::istream& fIn, std::map<std::string, std::string>& dictionary);
void SaveDictionary(std::ostream& fOut, std::map<std::string, std::string>& dictionary);
void SaveChanges(std::string userInput, std::map<std::string, std::string>& dictionary, std::map<std::string, std::string> dictionaryCopy, bool& isSaved, std::istream& input);
void WorkWithUnknownWorld(std::string searchWord, std::string userInput, std::map<std::string, std::string>& dictionaryCopy, bool& isEdit, std::istream& input);
void FindTranslation(std::string userInput, std::map<std::string, std::string> dictionaryCopy, bool& isFound);