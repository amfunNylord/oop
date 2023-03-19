#include <iostream>
#include <map>

std::map<const std::string, const std::string> entities = {
	{ "&quot;", "\"" },
	{ "&apos;", "’" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" }
};

std::string ConvertStrToEntities(std::string possibleEntity)
{
	for (auto& item : entities)
	{
		if (possibleEntity == item.first)
		{
			return item.second;
		}
	}
	return possibleEntity;
}