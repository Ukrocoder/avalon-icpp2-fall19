#pragma once
using char_array = char*;
namespace ext
{
	int len(char_array s);

	void concatenate(char_array& first, char_array second);

	char characterAt(char_array s, int position);

	void append(char_array &s, char input);
	
	char_array substring(char_array s, int start, int length);
}