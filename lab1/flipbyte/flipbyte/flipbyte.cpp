#include <iostream>
#include <fstream>

int FlipByte(unsigned char enteredByte)
{
	enteredByte = ((enteredByte & 0b1111) << 4) | ((enteredByte & 0b11110000) >> 4);
	enteredByte = ((enteredByte & 0b00110011) << 2) | ((enteredByte & 0b11001100) >> 2);
	enteredByte = ((enteredByte & 0b01010101) << 1) | ((enteredByte & 0b10101010) >> 1);
	return int(enteredByte);
}

bool IsInt(char* enteredByte)
{
	for (int i = 0; i < strlen(enteredByte); i++)
	{
		if (enteredByte[i] < '0' or enteredByte[i] > '9')
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Too few arguments\n";
		std::cout << "Example: flipbyte.exe <entered byte>\n";
		if (argv[2] != nullptr)
		{
			std::ofstream outputFile(argv[2]);
			outputFile << "Too few arguments\n";
			outputFile << "Example: flipbyte.exe <entered byte>\n";
		}
		return 0;
	}

	if (!IsInt(argv[1]))
	{
		std::cout << "Wrong entered byte, it is string\n";
		if (argv[2] != nullptr)
		{
			std::ofstream outputFile(argv[2]);
			outputFile << "Wrong entered byte, it is string\n";
		}
		return 0;
	}
	if (atoi(argv[1]) < 0 or atoi(argv[1]) > 255)
	{
		std::cout << "Wrong entered byte, it isn't in 0 - 255\n";
		if (argv[2] != nullptr)
		{
			std::ofstream outputFile(argv[2]);
			outputFile << "Wrong entered byte, it isn't in 0 - 255\n";
		}
		return 0;
	}

	unsigned char enteredByte = (unsigned char)atoi(argv[1]);

	int flippedByte = FlipByte(enteredByte);

	std::cout << flippedByte << '\n';
	
	if (argv[2] != nullptr)
	{
		std::ofstream outputFile(argv[2]);
		outputFile << flippedByte << '\n';
	}
}
