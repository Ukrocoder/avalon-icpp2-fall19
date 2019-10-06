#include <iostream>
#include "Main_Header.h"
//int const G = 10;
int main()
{
	setlocale(0, "");
	//lem::connection_test();
/*	long long int isbn;
	bool ans;
	std::cout << "Please, choose, whether you want do check ISBN-13 or ISBN-10 code?\n 1 = ISBN-13, 0 = ISBN-10\n";
	std::cin >> ans;
	if (ans) 
	{
		std::cout << "Please, enter your ISBN-13 code: ";
		std::cin >> isbn;
		lem::check_isbn(isbn, 13);
	}
	else
	{
		std::cout << "Please, enter your ISBN-10 code: ";
		std::cin >> isbn;
		lem::check_isbn(isbn, 10);
	}*/
	//bubble sort
	//=========================================================================
	/*int mass[10]{ 3, 5, 1, 8, 4, 2, 9, 10, 4, 6 };
	int size = 10;
	lem::bubble_sort(mass, size);
	for (int i = 0; i < size; ++i)
	{
		std::cout << mass[i]<<" ";
	}*/
	//=========================================================================
	int n = 100;
	int choice;
	lem::Student* p = lem::make_stud_list(n);
	std::cout << "How do you want to sort the list?\n1-Id, 2-Grade, 3-Name.";
	std::cin >> choice;
	lem::bubble_sort(p, n);//Make new sort for Student type with choice of parameters
	/*for (int i = 0; i < n; ++i) // For debug, shows the list;
	{
		std::cout << (p+i)->Id << ' ' << (p+i)->Grade << ' ' << (p+i)->Name << std::endl;
	}*/
	return 0;
}