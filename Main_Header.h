#pragma once
#include <string>
//#include "lem_lib.cpp"
namespace lem
{
	
	int digit(int x, int pos);

	void task_1();

	void task_2();

	struct triangle
	{
		std::string color;

		int a, b, c;

		float width;

		bool fill;
	};

}