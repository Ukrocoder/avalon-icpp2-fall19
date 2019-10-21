#include <iostream>
#include "Main_Header.h"
//#include "Main_Header.h"
//int const G = 10;
int n = 100;

int main()
{
	//setlocale(0, "");
	bool flag = true;
	while (flag)
	{
		flag = false;
		std::cout << "Enter your date in the following order: day, month, year. Write month as a number. " << std::endl;
		lem::Date input;
		int x;
		std::cin >> input.day;
		std::cin >> x;
		input.month = static_cast<lem::Month>(x);
		std::cin >> input.year;
		input.year;
		if (!correct_date(input))
			{
				std::cout << "You have written an invalid date, try once more." << std::endl;
				flag = true;
			}
	}
	lem::Date *p = lem::make_mass(n);
	lem::TimeDelta *ip = new lem::TimeDelta[n];
	for (int i = 0; i < n; ++i)
	{
		*(ip + i) = lem::countJND(*(p + i));
	}
	lem::bubble_sort(ip, n);
}