#include <iostream>
#include "String.h"

String::String()
{
	startChar = nullptr;
	stringLength = 0;
}

String::String(const char* str)
{
	int i{};

	while (str[i++] != '\0')
	{
	}

	stringLength = i - 1;

	CustomChar* pChar = new CustomChar[stringLength+1];

	for (i = 0; i < stringLength; i++)
	{
		pChar[i].character = str[i];
		pChar[i].pNext = &pChar[i+1];
	}

	pChar[i].character = '\0';
	pChar[i].pNext = nullptr;

	startChar = &pChar[0];

}

void String::Print() const
{
	CustomChar* p = startChar;

	while (p->character != '\0')
	{
		std::cout << p->character;
		p = p->pNext;
	}

}

int String::StringLength() const
{
	return stringLength;
}

void String::Strcpy(const char* str)
{
	int anotherStringLength{};
	CustomChar* p = startChar;

	while (str[anotherStringLength++] != '\0')
	{
	}

	anotherStringLength--;

	if (anotherStringLength > stringLength)
	{
		int i{ stringLength };
		int j{};
		CustomChar* pChar = new CustomChar[anotherStringLength-stringLength];

		for ( ; i < anotherStringLength - 1; i++, j++)
		{
			pChar[j].character = str[i+1];
			pChar[j].pNext = &pChar[j + 1];
		}

		pChar[j].character = '\0';
		pChar[j].pNext = nullptr;

		for (int j = 0; j < stringLength; j++)
		{
			p->character = str[j];
			p = p->pNext;
		}

		p->character = str[stringLength];
		p->pNext = &pChar[0];
		
	}
	else
	{
		for (int i = 0; i < anotherStringLength; i++)
		{
			p->character = str[i];
			p = p->pNext;
		}

		p->character = '\0';
	}

	stringLength = anotherStringLength;
	
}

void String::Strcpy(String& str)
{
	int anotherStringLength{ str.StringLength() };
	startChar = str.startChar;

	stringLength = str.StringLength();

}

bool String::Strcmp(const char* str) const
{
	int anotherStringLength{};
	CustomChar* p = startChar;

	while (str[anotherStringLength++] != '\0')
	{
	}

	anotherStringLength--;

	if (anotherStringLength != StringLength())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < anotherStringLength; i++)
		{
			if (p->character != str[i])
			{
				return false;
			}
			p = p->pNext;
		}
	}

	return true;
}

bool String::Strcmp(String& str) const
{
	CustomChar* p1 = startChar;
	CustomChar* p2 = str.startChar;

	if (StringLength() != str.StringLength())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < StringLength(); i++)
		{
			if (p1->character != p2->character)
			{
				return false;
			}
			p1 = p1->pNext;
			p2 = p2->pNext;
		}
	}

	return true;
}
