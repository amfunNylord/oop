#include <fstream>
#include <iostream>
#include <charconv>
#include <string>

// тип должен быть такой же
unsigned int FlipByte(unsigned char enteredByte)
{
	enteredByte = ((enteredByte & 0b1111) << 4) | ((enteredByte & 0b11110000) >> 4);
	enteredByte = ((enteredByte & 0b00110011) << 2) | ((enteredByte & 0b11001100) >> 2);
	enteredByte = ((enteredByte & 0b01010101) << 1) | ((enteredByte & 0b10101010) >> 1);
	return static_cast<unsigned int>(enteredByte);
}

// странный метод
bool IsInt(char* enteredByte)
{
	int result;
	std::string enteredByteStr = static_cast<std::string>(enteredByte);
	std::from_chars_result res = std::from_chars(enteredByteStr.data(), enteredByteStr.data() + enteredByteStr.size(), result);
	return (res.ec == std::errc{});
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid options count\nExample: flipbyte.exe <entered byte>\n";
		return 1;
	}

	if (!IsInt(argv[1]))
	{
		std::cout << "Wrong entered byte, it is string\n";
		return 1;
	}
	int intByte = atoi(argv[1]);
	if (intByte < 0 || intByte > 255)
	{
		std::cout << "Wrong entered byte, it isn't in 0 - 255\n";
		return 1;
	}

	unsigned char enteredByte = static_cast<unsigned char>(intByte);

	unsigned int flippedByte = FlipByte(enteredByte);

	std::cout << flippedByte << '\n';
}
