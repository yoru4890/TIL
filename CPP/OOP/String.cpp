#include <iostream>
#include "String.h"

String::String() : startChar{}, endChar{}, stringLength {}
{
}

String::String(const char* str) : stringLength{}
{
	while (str[stringLength++] != '\0')
	{
	}

	stringLength--;

	CustomChar* pChar = new CustomChar;
	CustomChar* pTemp;
	startChar = pChar;

	for (int i = 0; i < stringLength; i++)
	{
		pTemp = pChar;
		pChar = new CustomChar;
		pTemp->character = str[i];
		pTemp->pNext = pChar;
	}

	pChar->character = '\0';
	pChar->pNext = nullptr;
	endChar = pChar;

}

String::~String()
{
	CustomChar* p = startChar;
	CustomChar* pNext;

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}
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
		CustomChar* pChar = new CustomChar;
		pChar = endChar;
		CustomChar* pTemp;

		for (int i=stringLength; i < anotherStringLength; i++)
		{
			pTemp = pChar;
			pChar = new CustomChar{};
			pTemp->character = str[i];
			pTemp->pNext = pChar;
		}

		pChar->character = '\0';
		pChar->pNext = nullptr;

		endChar = pChar;

		for (int i = 0; i < stringLength; i++)
		{
			p->character = str[i];
			p = p->pNext;
		}
		
	}
	else
	{
		CustomChar* pNext;

		for (int i = 0; i < anotherStringLength; i++)
		{
			p->character = str[i];
			p = p->pNext;
		}

		p->character = '\0';
		endChar = p;
		p = p->pNext;
		
		for (int i = anotherStringLength; i < stringLength - anotherStringLength; i++)
		{
			pNext = p->pNext;
			delete p;
			p = pNext;
		}

		endChar->pNext = nullptr;
	}

	stringLength = anotherStringLength;
	
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

void String::AddStr(const char* str)
{
	int anotherStringLength{};
	CustomChar* p = startChar;

	while (str[anotherStringLength++] != '\0')
	{
	}

	anotherStringLength--;

	CustomChar* pChar = new CustomChar;
	CustomChar* pTemp;
	pChar = endChar;

	for (int i = 0; i < anotherStringLength; i++)
	{
		pTemp = pChar;
		pChar = new CustomChar{};
		pTemp->character = str[i];
		pTemp->pNext = pChar;
	}

	pChar->character = '\0';
	pChar->pNext = nullptr;

	endChar = pChar;

	stringLength += anotherStringLength;
}


