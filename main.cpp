#include "Main_header.h"
#include <iostream>
int main()
{
	int input;
	bool flag = true;

	while (flag)
	{
	//	book::creat();
		std::cout << "Choose action:\n1 - find book by its name.\n2 - add new book.\n3 - change existing book.\n4 - show list of books sorted by its author and name.\n5 - show statistics about summary price and quantity of books.\n0 - exit the programm."<<std::endl;
		std::cin >> input;
		system("cls");
		switch (input)
		{
		case 0:
			flag = false;
			break;
		case 1:
			book::find();
			break;
		case 2:
			book::add();
			break;
		case 3:
			book::redact();
			break;
		case 4:
			book::show_list();
			break;
		case 5:
			book::show_stat();
			break;
		}
	}
	return 0;
}