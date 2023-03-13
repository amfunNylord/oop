#include <iostream>
#include <map>

std::map<const std::string, const char> entities = {
	{ "quot", '"' },
	{ "apos", '’' },
	{ "lt", '<' },
	{ "gt", '>' },
	{ "amp", '&' }
};

char ConvertStrToEntities(std::string possibleEntity)
{
	for (auto& item : entities)
	{
		if (possibleEntity == item.first)
		{
			return item.second;
		}
	}
	return 'N';
}