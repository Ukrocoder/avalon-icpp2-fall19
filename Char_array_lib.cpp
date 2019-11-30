#include "Char_array.h"
namespace ext
{
	//Returns the index of the last element (\0).
	int len(char_array s)
	{
		int out=0;
		while (s[out] != '\0') { ++out; }
		return out;
	}

	//Concatenates two char arrays and renames first pointer to the new char array.
	void concatenate(char_array &first, char_array second)
	{
		char_array out = new char[len(first)+len(second)-1];
		for (int i = 0; i < len(first); ++i)
		{
			
			out[i] = first[i];
		}

		for (int i = 0; i < len(second); ++i)
		{
			out[len(first) + i] = second[i];
		}

		/*
		for (int i = len(first); i < len(first)+len(second); ++i)
		{
			out[i] = second[i-len(first)];
		}*/
		out[len(first) + len(second) ] = '\0';
		delete[] first;
		first = out;
	}

	//Returns character given counting from 1.
	char characterAt(char_array s, int position)
	{
		if ((position <=0) ||(position>len(s))) { s[0]; }
		else { return s[position - 1]; }
	}

	//Append the char in the end of array and renames pointer to the new char array.
	 void append(char_array &s, char input)
	{
		char_array out = new char[len(s) + 2];
		for (int i = 0; i < len(s); ++i)
		{
			out[i] = s[i];
		}
		out[len(s)] = input;
		out[len(s)+1] = '\0';
		//delete[] s;
		s = out;
	}

	//Return new array which contains first "length" symbols from "start"(counting from 1).
	char_array substring(char_array s, int start, int length)
	{
		char_array out = new char[length+1];
		for (int i = start - 1; i < start + length; ++i)
		{
			out[i-(start-1)] = s[i];
		}
		out[length] = '\0';
		return out;
	}
}