#include "HTMLDecode.h"
#include <iostream>

std::string Decode(std::string const& html)
{
	std::string decodedStr;
	size_t indexStart = 0, indexEnd = 0;
	// bool ampFound
	while ((indexStart = html.find('&', indexStart)) != std::string::npos)
	{
		decodedStr.append(html, indexEnd, indexStart - indexEnd);
		indexStart++;
		indexEnd = indexStart;
		size_t lengthWordBetweenSymbols = html.find(';', indexEnd) - indexEnd;
		
		std::string possibleEntity = "&";
		possibleEntity.append(html, indexEnd, lengthWordBetweenSymbols);
		possibleEntity += ";";
		
		std::string convertedEntity = ConvertStrToEntities(possibleEntity);
		decodedStr += convertedEntity;
		indexStart += lengthWordBetweenSymbols + 1;
		indexEnd = indexStart;
	}
	if (indexStart != html.length())
	{
		decodedStr.append(html, indexEnd, html.length() - indexEnd);
	}
	return decodedStr;
}