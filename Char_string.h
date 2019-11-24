#pragma once
namespace ext
{
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};

	void append(charString* str, char symbol);

	void print(charString* str);

	void concatenate(charString* str1, charString* str2);

	void removeChars(charString* str1, int start, int length);

	charString* substring(charString* str1, int start, int length);

	char characterAt(charString* str, int position);
}