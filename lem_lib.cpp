#include "Main_Header.h"
#include <math.h>
#include <iostream>
#include <fstream>
std::ifstream input;
std::ofstream output;
std::fstream in_output;
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
		output_2.open("unlucky.txt", std::istream::app);
		for (int i = 0; i < 1000; ++i)
		{
			input >> ticket;
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
		input.open("triangle.txt");
		output.open("triangle_out.txt");

		for (int i = 0; i < 100; ++i)
		{
			input >> x;
			output << x;
		}
		input.close();
		output.close();
	}
	
	void task_3()
	{
		int id, maxid = 0;
		float buf;
		float max = 0.0;
		athlete * mass = new athlete[20];
		input.open("athletes.txt");


		for (int i = 0; i < 20; ++i)
		{
			input >> buf;
			input >> mass[i].name;
			input >> mass[i].surname;
		}
		input.close();
		input.open("result.txt");
		for (int i = 0; i < 60; ++i)
		{
			input >> id >> buf;
			if (mass[id - 1].res_1 == 0) { mass[id - 1].res_1 = buf; }
			else
			{
				if (mass[id - 1].res_2 == 0) { mass[id - 1].res_2 = buf; }
				else { mass[id - 1].res_3 = buf; }
			}
			if (max < mass[id - 1].res_1) { max = mass[id - 1].res_1; maxid = id - 1; }
			if (max < mass[id - 1].res_2) { max = mass[id - 1].res_2; maxid = id - 1; }
			if (max < mass[id - 1].res_3) { max = mass[id - 1].res_3; maxid = id - 1; }

		}
		std::cout << mass[maxid].name << ' ' << mass[maxid].surname << ": " << max;
		input.close();
	}

}