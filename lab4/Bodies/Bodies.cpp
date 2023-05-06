// bodies.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "BodyController.h"

const std::string COMMAND_HELPER = "Commands:\n  AddBody <body_type> <density> \n   Body types:\n    1 - Cone <base_radius> <height>\n    2 - Cylinder <base_radius> <height>\n    3 - Parallelepiped <width> <height> <depth>\n    4 - Sphere <radius>\n  Info\n  GetBodyWithBiggestMass\n  GetLightestBodyInWater";

int main()
{
	std::vector<std::shared_ptr<CBody>> bodiesVector;
	CBodyController bodyController(std::cin, std::cout, bodiesVector);
	std::cout << COMMAND_HELPER << std::endl;
	while (!std::cin.eof() && !std::cin.fail())
	{	
		std::cout << "> ";
		if (!bodyController.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
			std::cout << COMMAND_HELPER << std::endl;
		}
	}
	return 0;
}