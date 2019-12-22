#include "Main_header.h"
#include <string>
#include <fstream>
#include <iostream>

namespace book
{
	std::ifstream in_file;
	std::ofstream out_file;
	Book buf;
	extern const int SIZE;
	/*====================================================================*/
	std::ostream& operator << (std::ostream& out, Book book)
	{
		out <<"Id: "<< book.id << ", author: " << book.author << ", book name: " << book.title << ", price: " << book.price << ", quantity " << book.quantity;
		return out;
	}
	/*====================================================================*/
	Book* read( int &file_size)
	{
		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		file_size = (in_file.tellg() / sizeof(Book));
		Book* mass = new Book[file_size];
		in_file.seekg(0);
		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(mass + i), sizeof(Book));
		}
		in_file.close();
		return mass;
	}
	/*====================================================================*/
	int len(char* s)
	{
		int out = 0;
		while (s[out] != '\0') { ++out; }
		return out;
	}
	/*====================================================================*/
	void swap(Book& b1, Book& b2)
	{
		Book buf;
		buf = b2;
		b2 = b1;
		b1 = buf;
	}
	/*====================================================================*/
	char* concatenate(char* first, char* second)
	{
		char* out = new char[len(first) + len(second) - 1];
		for (int i = 0; i < len(first); ++i)
		{

			out[i] = first[i];
		}

		for (int i = 0; i < len(second); ++i)
		{
			out[len(first) + i] = second[i];
		}

		out[len(first) + len(second)] = '\0';
		return out;
	}
	/*====================================================================*/
	void bubble_sort(Book * mass, int size)
	{
		int x=0;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < size-1-x; ++i)
			{
				
				if (strcmp(concatenate(mass[i].author, mass[i].title), concatenate(mass[i+1].author, mass[i+1].title))>0 )
				{
					swap(mass[i], mass[i + 1]);
					flag = true;
				}
			}
			++x;
		}
	}
	/*====================================================================*/
	void find()
	{
		int file_size;
		char name[SIZE]{};
		bool flag = true;

		std::cout << "Enter book's title." << std::endl;
		std::cin >> name;

		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		file_size = (in_file.tellg()/sizeof(Book));

		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(&buf), sizeof(Book));
			if (strcmp(buf.title, name)==0)
			{
				std::cout << buf<<std::endl;
				flag = false;
				break;
			}
		}	
		in_file.close();

		if (flag)
		{
			std::cout << "No book with such name." << std::endl;
		}
	}
	/*====================================================================*/
	void add()
	{
		int size;
		std::cout<<"Enter book's title, author, price and then quantity (only in that order)." << std::endl;
		std::cin >> buf.title >> buf.author >> buf.price >> buf.quantity;

		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		size = (in_file.tellg() / sizeof(Book));
		in_file.close();
		buf.id = size + 1;

		out_file.open("source.bin", std::istream::out |std::istream::app | std::istream::binary);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}
	/*====================================================================*/
	void redact()
	{
		int id, file_size;
		std::cout << "Enter the id of book which you want to change."<<std::endl;
		std::cin >> id;
		--id;

		Book* mass = read(file_size);
		std::cout << mass[id]<<std::endl;
		std::cout << "Now enter book's news title, author, price and then quantity (only in that order)." << std::endl;
		std::cin >> mass[id].title >> mass[id].author >> mass[id].price >> mass[id].quantity;
		out_file.open("source.bin", std::istream::out | std::istream::binary);
		out_file.write(reinterpret_cast<char*>(mass), sizeof(Book)*file_size);
		
		out_file.close();
		delete[] mass;
	}
	/*====================================================================*/
	void show_list()
	{
		int file_size;

		Book* mass = read(file_size);
		bubble_sort(mass, file_size);

		for (int i = 0; i < file_size; ++i)
		{
			std::cout << mass[i] << std::endl;
		}
		delete[] mass;
	}
	/*====================================================================*/
	void show_stat()
	{
		int file_size;
		int sum_price=0;
		int sum_quantity=0;

		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		file_size = (in_file.tellg() / sizeof(Book));
		in_file.seekg(0);

		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(&buf), sizeof(Book));
			sum_price += buf.price;
			sum_quantity += buf.quantity;
		}
		in_file.close();

		std::cout << "Summary price of books: " << sum_price << ", summary quantity: " << sum_quantity << std::endl;
	}
}