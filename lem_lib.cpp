#include <iostream>
#include <math.h>
#include <sstream>
#include "Main_Header.h"
#include <fstream>

namespace lem
{
	/*int GetRandomValue(int min, int max, bool isDebugMode = false)//Stolen from Extention.h
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}*/
	int digit(int x, int pos)
	{
		int out = x / static_cast<int>(pow(10, pos - 1)) % 10;
		return out;
	}
	void task()
	{
		int size;
		int input;
		std::cin >> input;
		std::ifstream in;
		in.open("triangle.bin", std::istream::in | std::istream::binary);

		in.seekg(0, std::ios_base::end);
		size=in.tellg()/sizeof(triangle);

		in.close();
	}

}