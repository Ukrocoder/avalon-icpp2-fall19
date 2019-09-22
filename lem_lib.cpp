#include <iostream>
#include "Main_Header.h"
namespace lem
{
	void connection_test()
	{
		std::cout << "Yeah, boy, i'm connected properly!";
	}
	void check_isbn(long long int x)
	{
		if (isbn_logic(x))
		{
			std::cout <<std::endl<< "Your ISBN code is valid.";
		}
		else
		{
			std::cout << std::endl << "Your ISBN code is invalid.";
		}
	}
	bool isbn_logic(long long int a)
	{
		long long t = 1000000000000;
		int sum = 0;
	for (int i=1;i<13;i++)
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
		std::cout << "i = " << i <<", a = " << a << ", t = " << t<<std::endl;
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
	//(x / 1000000000000 + x%1000000000000/100000000000*3+x%100000000000/10000000000+x%10000000000/1000000000*3+x%1000000000/100000000+x%100000000/10000000*3+x%10000000/1000000+x%1000000/100000*3+x%100000/10000+x%10000/1000*3+x%1000/100+x%100/10*3+x%10)%10==0
}