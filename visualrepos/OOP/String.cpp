#include <iostream>
#include "String.h"

String::String()
{
}

String::String(const char str[12])
{
	int i{};

	while (str[i++] != '\0')
	{
	}

	stringLength = i;

	CustomChar* pChar = new CustomChar[stringLength + 1];

	for (i = 0; i < stringLength + 1; i++)
	{
		pChar[i].character = str[i];
		pChar[i].pNext = &pChar[i+1];
	}

	startChar = &pChar[0];
	endChar = &pChar[i];

}

void String::Print() const
{
	CustomChar* p = startChar;

	while (p)
	{
		std::cout << p;
		p = p->pNext;
	}
}
