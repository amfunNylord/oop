#include <iostream>
#include <string>
#include "HTMLDecode.h"

int main()
{
	std::string html;
	while (getline(std::cin, html))
	{
		std::string decodedHtml = Decode(html);
		std::cout << decodedHtml << '\n';
	}
	return 0;
}