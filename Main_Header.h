#pragma once
//#include "lem_lib.cpp"
#include <string>
namespace lem
{
	struct Student
	{
		int Id;
		int Grade;
		std::string Name;
	};
	struct Agent
	{
		int monthlySales[12];
	};
	float median(Agent x);
	void connection_test();
	Agent * make_agent(int na);
	void check_isbn(long long int x, int f);
	void better_than(Student * ptr, int p);
	bool isbn_logic(long long int a, int version);
	void bubble_sort(Student* ptr, int size, int choice);
	int GetRandomValue(int min, int max, bool isDebugMode = false);
	Student* make_stud_list(int n);
}