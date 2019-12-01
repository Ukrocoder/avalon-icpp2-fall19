#include <iostream>
#include <random>
#include <math.h>
#include <exception>
#include <sstream>
#include "Main_Header.h"
#include <fstream>
extern std::ifstream input;
extern std::ofstream output;
extern std::fstream in_output;

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

	int perimetr(triangle x)
	{
		return x.a + x.b + x.c;
	}

	float square(triangle x)
	{
		float p = 0.5F * perimetr(x);
		return sqrt(p * (p - x.a) * (p - x.b) * (p - x.c));
	}

	void task_1()
	{
		int ticket;
		std::ofstream output_2;
		input.open("tickets.txt");
		output.open("lucky.txt", std::istream::app);
		output_2.open("unlucky.txt", std::istream::app );
		for (int i = 0; i < 1000; ++i)
		{
			input>>ticket;
			if (digit(ticket, 6) + digit(ticket, 5) + digit(ticket, 4) == digit(ticket, 3) + digit(ticket, 2) + digit(ticket, 1))
			{
				output << ticket << std::endl;
			}
			else
			{
				output_2 << ticket << std::endl;
			}
		}
		input.close(); output.close(); output_2.close();
		}
	std::ifstream& operator >>(std::ifstream& input, triangle& x)
	{
		std::string line;
		std::getline(input, line);

		std::istringstream temp(line);

		input >> x.color >> x.a >> x.b >> x.c >> x.width >> x.fill;
		input.clear('\n');
		return input;
	}

	std::ofstream& operator <<(std::ofstream& output, triangle x)
	{
		output << x.a << ' ' << x.b << ' ' << x.c << ' ' << perimetr(x) << ' ' << square(x) << ' ' << x.width << ' ' << x.fill << ' ' << x.color << std::endl;
		return output;
	}

	void task_2()
	{
		triangle x;
		triangle y;
		input.open("triangle.txt");
		output.open("triangle_out.txt");

		input >> x;
		input >> y;
		for (int i = 0; i < 100; ++i)
		{
		input >> x;
		output << x;
		}
		input.close();
		output.close();
	}
}