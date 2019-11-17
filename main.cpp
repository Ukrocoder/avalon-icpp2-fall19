#include <iostream>
#include "Char_array.h"
//#include "Main_Header.h"

int main()
{
	//setlocale(0, "");
	char_array x1 = new char[6]{"first"};
	char_array x2 = new char[8]{" second"};
	ext::concatenate(x1, x2);
	ext::append(x1, '!');
	
	for (int i = 0; i < ext::len(x1); ++i)
	{
		std::cout << x1[i];
	}
	std::cout << std::endl;
	x1 = ext::substring(x1, 3, 5);
	for (int i = 0; i < ext::len(x1); ++i)
	{
		std::cout << x1[i];
	}
}