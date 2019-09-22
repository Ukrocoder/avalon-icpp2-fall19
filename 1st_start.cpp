#include <iostream>
#include "Main_Header.h"
int main()
{
	setlocale(0, "");
	//lem::connection_test();
	long long int isbn;
	bool ans;
	std::cout << "Please, choose, which type do you want to use:\n 0 = ISBN 10, 1 = ISBN-13. ";
	std::cin >>  ans;
	if (ans)
	{
		std::cout << "Please, enter your ISBN-13 code: ";
		std::cin >> isbn;
		lem::check_isbn(isbn);
	}
	else
	{
		std::cout << "Please, enter your ISBN-13 code: ";
		std::cin >> isbn;
		lem::check_isbn10(isbn);
	}

	return 0;
}