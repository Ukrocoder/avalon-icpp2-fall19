#include <iostream>
#include <string>
#include "header.h"
#include <cstdio>
#include <limits>
int main()
{

	const int size = 24;
	std::string name = "bool";
	setlocale(0, "");
	std::cout << "Тип переменной		|    Размер     |	          Значение               |  Количество    "<<std::endl;
	std::cout << "			|     байт    	|    Минимальное     |    Максимальное    | значимых бит   "<< std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
	std::printf("%-24s|%15d|%20d|%20d|%16d\n", name.c_str(), sizeof(bool), std::numeric_limits<bool>::min(), std::numeric_limits<bool>::max(), 1);
	name = "unsigned short";
	std::printf("%-24s|%15d|%20u|%20u|%16d\n", name.c_str(), sizeof(unsigned short), std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max(), sizeof(unsigned short)*8);
	name = "short";
	std::printf("%-24s|%15d|%20d|%20d|%16d\n", name.c_str(), sizeof(short), std::numeric_limits<short>::min(), std::numeric_limits<short>::max(), sizeof(short) * 8-1);
	name = "unsigned int";
	std::printf("%-24s|%15d|%20u|%20u|%16d\n", name.c_str(), sizeof(unsigned int), std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max(), sizeof(unsigned int) * 8);
	name = "int";
	std::printf("%-24s|%15d|%20d|%20d|%16d\n", name.c_str(), sizeof(int), std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), sizeof(int) * 8 - 1);
	name = "unsigned long";
	std::printf("%-24s|%15d|%20u|%20u|%16d\n", name.c_str(), sizeof(unsigned long), std::numeric_limits<unsigned long>::min(), std::numeric_limits<unsigned long>::max(), sizeof(unsigned long) * 8);
	name = "long";
	std::printf("%-24s|%15d|%20d|%20d|%16d\n", name.c_str(), sizeof(long), std::numeric_limits<long>::min(), std::numeric_limits<long>::max(), sizeof(long) * 8 - 1);
	name = "unsigned long long int";
	std::printf("%-24s|%15d|%20llu|%20llu|%16d\n", name.c_str(), sizeof(unsigned long long int), std::numeric_limits<unsigned long long int >::min(), std::numeric_limits<unsigned long long int>::max(), sizeof(unsigned long long int) * 8);
	name = "long long";
	std::printf("%-24s|%15d|%20lld|%20lld|%16d\n", name.c_str(), sizeof(long long int), std::numeric_limits<long long int>::min(), std::numeric_limits<long long int>::max(), sizeof(long long int) * 8-1);
	name = "char";
	std::printf("%-24s|%15d|%20d|%20d|%16d\n", name.c_str(), sizeof(char), std::numeric_limits<char>::min(), std::numeric_limits<char>::max(), sizeof(char) * 8);
	name = "float";
	std::printf("%-24s|%15d|%20e|%20e|%16d\n", name.c_str(), sizeof(float), std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), sizeof(float) * 8);
	name = "double";
	std::printf("%-24s|%15d|%20e|%20e|%16d\n", name.c_str(), sizeof(double), std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), sizeof(double) * 8);
	return 0;
}
