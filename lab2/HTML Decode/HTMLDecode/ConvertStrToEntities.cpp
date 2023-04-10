#include <iostream>
#include <map>

std::map<const std::string, const std::string> entities = {
	{ "&quot;", "\"" },
	{ "&apos;", "’" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" }
};

std::string ConvertStrToEntities(const std::string possibleEntity)
{
	return entities[possibleEntity] != "" ? entities[possibleEntity] : possibleEntity;
}