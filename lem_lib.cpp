#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "Main_Header.h"
namespace lem
{

	//extern int G;
	Student* make_stud_list(int n)
	{
		int ln;
		std::string name;
		Student* ptr = new Student[n];
		for (int i = 0; i < n; ++i)
		{
			(ptr + i)->Id = GetRandomValue(1, 1000);
			(ptr + i)->Grade = GetRandomValue(1, 100);
			ln= GetRandomValue(3, 6);
			for (int j = 0; j < ln; ++j)
			{
			
			(ptr+i)->Name+= GetRandomValue('a', 'z');
			}

		}
		return ptr;
	}

	int GetRandomValue(int min, int max, bool isDebugMode)//Stolen from Extention.h
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}

	void connection_test()
	{
		std::cout << "Yeah, boy, i'm connected properly!"<<std::endl;
	}
	void check_isbn(long long int x, int f)
	{
		if (isbn_logic(x,f))
		{
			std::cout <<std::endl<< "Your ISBN code is valid.";
		}
		else
		{
			std::cout << std::endl << "Your ISBN code is invalid.";
		}
	}
	bool isbn_logic(long long int a, int version)
	{
		long long t = pow(10, version-1);
		int sum = 0;
	for (int i=1;i<version;i++)
	{ 

		if (i % 2 == 1)
		{
			sum += a / t;
		}
		else 
		{
			sum += a / t * 3;
		}
		a %= t;
		t /= 10;
		std::cout << "i = " << i <<", a = " << a << ", t = " << t<<std::endl; //for debug use only!
	}
	sum += a;
	if (sum % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	}
	void bubble_sort(int* ptr, int size)
	{
		int buffer;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < size-1; ++i)
			{
				if (*(ptr + i) > * (ptr + i + 1))
				{
					buffer = *(ptr + i);
					*(ptr + i) = *(ptr + i + 1);
					*(ptr + i + 1) = buffer;
					flag = true;
				}
			}
		}
	}
	//(x / 1000000000000 + x%1000000000000/100000000000*3+x%100000000000/10000000000+x%10000000000/1000000000*3+x%1000000000/100000000+x%100000000/10000000*3+x%10000000/1000000+x%1000000/100000*3+x%100000/10000+x%10000/1000*3+x%1000/100+x%100/10*3+x%10)%10==0
}