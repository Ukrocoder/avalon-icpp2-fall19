#include <iostream>
#include "Char_string.h"
//#include "Main_Header.h"
/*struct student
{
	int id;
	int grade;
	student* next;
};
void print(student* ptr)
{
	student*temp = ptr;
	while (temp != nullptr)
	{
		std::cout << temp->id << ' ' << temp->grade << std::endl;
		temp = temp->next;
	}


}

void add_record(int id, int grade, student* &ptr)
{
	student* news = new student{ id, grade};
	news->next = ptr;
	ptr = news;
}
double count_average(student* ptr)
{
	double out;
	int count = 0, sum = 0;

	student* temp = ptr;
	while (temp != nullptr)
	{
		sum += temp->grade;
		++count;
		temp = temp->next;
	}
	out = static_cast<double>(sum) / count;
	return out;
}*/
int main()
{
	//setlocale(0, "");
	/*char_array x1 = new char[6]{"first"};
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
	}*/


	//Declaration
	ext::charString* s1 = new ext::charString{'e'};
	ext::charString* s2 = new ext::charString{'x'};
	ext::charString* s3 = new ext::charString{'t'};
	ext::charString* ptr = nullptr;

	//Linking part
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;
	s3->nextSymbol = nullptr;
	/*add_record(25, 90, ptr);
	print(ptr);
	std::cout << count_average(ptr)<<std::endl;*/

	ext::charString* ptr2 = new ext::charString{ 'e', nullptr };
	ext::append(ptr2, 'n');
	ext::append(ptr2, 't');//append test, next two parts should work properly
	ext::append(ptr2, 'i');
	ext::append(ptr2, 'o');
	ext::append(ptr2, 'n');
	ext::concatenate(ptr, ptr2);// concatenate test, should print "extention"
	ext::print(ptr);
	std::cout <<std::endl <<"===============================" << std::endl;
	ext::print(ext::substring(ptr, 3, 3)); //should print "ten"
	std::cout << std::endl << "===============================" << std::endl;
	std::cout << ext::characterAt(ptr, 7); //characterAt test, should print 'i'
	std::cout << std::endl << "===============================" << std::endl;
	ext::removeChars(ptr, 4, 3);// removeChars test, should print extion
	ext::print(ptr);

}