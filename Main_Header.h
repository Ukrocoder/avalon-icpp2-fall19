#pragma once
//#include "lem_lib.cpp"
namespace lem
{
	struct Student
	{
		int Id;
		int Grade;
		std::string Name;
	};
	void connection_test();
	void check_isbn(long long int x, int f);
	bool isbn_logic(long long int a, int version);
	void bubble_sort(int* ptr, int size);
	int GetRandomValue(int min, int max, bool isDebugMode = false);
	Student* make_stud_list(int n);
}