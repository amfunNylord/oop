#include "HTMLDecode.h"
#include <iostream>

std::string Decode(std::string const& html)
{
	std::string decodedStr = "";
	size_t posSearchStr = 0, indexStr = 0;
	while ((posSearchStr = html.find('&', posSearchStr)) != std::string::npos)
	{
		decodedStr.append(html, indexStr, posSearchStr - indexStr);
		posSearchStr++;
		indexStr = posSearchStr;
		size_t lengthWordBetweenSymbols = html.find(';', indexStr) - indexStr;
		if (lengthWordBetweenSymbols <= 4 && lengthWordBetweenSymbols >= 2)
		{
			std::string possibleEntity = "";
			possibleEntity.append(html, indexStr, lengthWordBetweenSymbols);
			char convertedEntity = ConvertStrToEntities(possibleEntity);
			if (convertedEntity == 'N')
			{
				decodedStr += possibleEntity;
			}
			else
			{
				decodedStr += convertedEntity;
			}
		}
		else
		{
			decodedStr.append(html, indexStr, lengthWordBetweenSymbols);
		}
		indexStr += lengthWordBetweenSymbols + 1;
	}
	if (indexStr != html.length())
	{
		decodedStr.append(html, indexStr, html.length() - indexStr);
	}
	return decodedStr;
}