#include <iostream>
#include "Char_array.h"
//#include "Main_Header.h"

int main()
{
	//setlocale(0, "");
	char_array x1 = new char[6]{"first"};
	char_array x2 = new char[8]{" second"};

	std::cout << ext::characterAt(x1, 2) << std::endl;//Should return "i"
	ext::concatenate(x1, x2);
	std::cout << ext::len(x1) << std::endl; //Should return 12, for debug usage.
	ext::append(x1, '!');
	
	for (int i = 0; i < ext::len(x1); ++i) //Should return "first second!"
	{
		std::cout << x1[i];
	}
	
	std::cout << std::endl;

	char_array x3 = ext::substring(x1, 3, 5); //Should return "rst s"
	for (int i = 0; i < ext::len(x3); ++i)
	{
		std::cout << x3[i];
	}
}