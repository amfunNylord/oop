// HTMLDecode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "HTMLDecode.h"

int main()
{
	std::string html;
	getline(std::cin, html);
	std::string decodedHtml = Decode(html);
	std::cout << decodedHtml << '\n';
	return 0;
}