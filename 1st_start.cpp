#include <iostream>
#include "Main_Header.h"
//int const G = 10;
int main()
{
	int maxmed = 0;
	setlocale(0, "");
	//lem::connection_test();
	int n = 100, na=10;
	int choice;
	lem::Student* p = lem::make_stud_list(n);
	lem::Agent* pa = lem::make_agent(na);
	std::cout << "How do you want to sort the list?\n1-Id, 2-Grade, 3-Name.";
	std::cin >> choice;
	lem::bubble_sort(p, n, choice);//Make new sort for Student type with choice of parameters

	for (int i = 0; i < n; ++i) // For debug, shows the list;
	{
		std::cout << (p+i)->Id << ' ' << (p+i)->Grade << ' ';
		std::cout << (p + i)->Name << std::endl;
	}
	lem::bubble_sort(p, n, 2);
	lem::better_than(p, n * 25 / 100);
	lem::better_than(p, n * 50 / 100);
	lem::better_than(p, n * 75 / 100);
	for (int i = 0; i < na; ++i)
	{
		if (lem::median(*(pa + i)) > maxmed) {maxmed = lem::median(*(pa + i));}
	}
	std::cout << "The biggest median is " << maxmed;
	return 0;
}