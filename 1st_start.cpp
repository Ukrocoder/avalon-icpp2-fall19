#include <iostream>
#include "Main_Header.h"
int main()
{
	setlocale(0, "");
	//lem::connection_test();
	long long int isbn;
	std::cout << "Please, enter your ISBN-13 code: ";
	std::cin >> isbn;
	lem::check_isbn(isbn);
	return 0;
}