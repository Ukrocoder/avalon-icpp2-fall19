#pragma once
namespace lem
{

	int digit(int x, int pos);

	void task_1();

	void task_2();

	void task_3();

	struct triangle
	{
		char* color = new char[10];

		int a;

		int b;

		int c;

		float width;

		bool fill;
	};
	struct athlete
	{
		char* name = new char[20];

		char* surname = new char[20];

		float res_1 = 0;

		float res_2 = 0;

		float res_3 = 0;

	};

}
