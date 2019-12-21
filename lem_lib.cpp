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
	std::ostream& operator << (std::ostream& out, Book book)
	{
		out <<"Id: "<< book.id <<", book name: " << book.title << ", author: " << book.author << ", price: " << book.price << ", quantity " << book.quantity;
		return out;
	}
	void equal(char* reciever, const char* giver)
	{
		int i = 0;
		//std::cout << x[i];
		while (giver[i] != '\0')
		{
			reciever[i] = giver[i];
			++i;
		}
		reciever[i] = '\0';
	}
/*	void creat()
	{
		int id=0;
		Book buf{1, "Author", "Title", 150.0, 5};
		char str[20]{"yay"};
		equal(buf.title, str);
		//char * p = new char[20]{"Author 1"};
		out_file.open("source.bin", std::istream::out | std::istream::binary);
		out_file.seekp(sizeof(Book)*id);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}*/

	int len(char* s)
	{
		int out = 0;
		while (s[out] != '\0') { ++out; }
		return out;
	}

	void swap(Book& b1, Book& b2)
	{
		Book buf;
		buf = b2;
		b2 = b1;
		b1 = buf;
	}

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

	void bubble_sort(Book * mass, int size)
	{
		int x=0;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < size-1-x; ++i)
			{
				if (concatenate(mass[i].author, mass[i].title) > concatenate(mass[i].author, mass[i].title))
				{
					swap(mass[i], mass[i + 1]);
					flag = true;
				}
			}
			++x;
		}
	}
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
			if (buf.title == name)
			{
				std::cout << buf<<std::endl;
				flag = false;
			}
		}
		
		in_file.close();

		if (flag)
		{
			std::cout << "No book with such name." << std::endl;
		}
	}
	void add()
	{
		int size;
		//char title[20], char author[20], float price, int quantity
		std::cout<<"Enter book's title, author, price and then quantity (only in that order)." << std::endl;
		std::cin >> buf.title >> buf.author >> buf.price >> buf.quantity;

		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		size = (in_file.tellg() / sizeof(Book));
		in_file.close();
		buf.id = size + 1;

		out_file.open("source.bin", std::istream::out | std::istream::binary);
		out_file.seekp(0, std::istream::end);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}
	void redact()
	{
		int id;

		std::cout << "Enter the id of book which you want to change."<<std::endl;
		std::cin >> id;
		buf.id = id;
		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(id * sizeof(Book));
		in_file.read(reinterpret_cast<char*>(&buf), sizeof(Book));
		std::cout << buf << std::endl;
		in_file.close();

		std::cout << "Now enter book's news title, author, price and then quantity (only in that order)." << std::endl;
		std::cin>> buf.title >> buf.author >> buf.price >> buf.quantity;
		out_file.open("source.bin", std::istream::out | std::istream::binary);
		out_file.seekp(sizeof(Book)*id);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}
	void show_list()
	{
		int file_size;
		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		file_size = (in_file.tellg() / sizeof(Book));
		Book* mass = new Book[file_size];

		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(mass+i), sizeof(Book));
		}
		in_file.close();

		bubble_sort(mass, file_size);

		for (int i = 0; i < file_size; ++i)
		{
			std::cout << mass[i] << std::endl;
		}

		delete[] mass;
	}
	void show_stat()
	{
		int file_size;
		int sum_price=0;
		int sum_quantity=0;

		in_file.open("source.bin", std::istream::in | std::istream::binary);
		in_file.seekg(0, std::istream::end);
		file_size = (in_file.tellg() / sizeof(Book));

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