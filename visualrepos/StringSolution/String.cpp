#include <iostream>
#include "String.h"

String::String() : mLength{}
{
	mString = new char;
	*mString = '\0';
}

String::String(int size) : mLength{ size }
{
	mString = new char[size+1];

	for (int i = 0; i < size; i++)
	{
		mString[i] = ' ';
	}

	mString[size] = '\0';
}

String::String(const char* str) : mLength{}
{
	while (str[mLength++] != '\0');

	mString = new char[mLength--];

	for (int i = 0; i < mLength; i++)
	{
		mString[i] = str[i];
	}

	mString[mLength] = '\0';
}

String::String(const String& str)
{
	mLength = str.mLength;
	mString = new char[mLength + 1];

	for (int i = 0; i < mLength; i++)
	{
		mString[i] = str.mString[i];
	}

	mString[mLength] = '\0';
}

String::~String()
{
	if (mLength)
	{
		delete[] mString;
	}
	else
	{
		delete mString;
	}
	
}

String* String::Print()
{
	std::cout << mString << std::endl;

	return this;
}

int String::Length()
{
	return mLength;
}

String String::operator+(const String& str) const
{
	String temp;
	delete temp.mString;
	temp.mLength = mLength + str.mLength;

	temp.mString = new char[temp.mLength+1];

	int i{};
	for (; i < mLength; i++)
	{
		temp.mString[i] = mString[i];
	}

	for (int j = 0; i < temp.mLength; i++, j++)
	{
		temp.mString[i] = str.mString[j];
	}

	temp.mString[temp.mLength] = '\0';

	return temp;
}

String& String::operator+=(const String& str)
{
	String temp(*this);

	if (mLength)
	{
		delete[] mString;
	}
	else
	{
		delete mString;
	}

	mLength += str.mLength;
	mString = new char[mLength + 1];

	int i{};

	for (; i < temp.mLength; i++)
	{
		mString[i] = temp.mString[i];
	}

	for (int j = 0; i < mLength; i++, j++)
	{
		mString[i] = str.mString[j];
	}

	mString[mLength] = '\0';

	return *this;
}

char& String::operator[](int index)
{
	return mString[index];
}

String& String::operator=(const String& str)
{
	if (mLength == str.mLength)
	{
		int i = --mLength;
		int j = str.mLength;
		mLength++;
		if (i == j)
		{
			return *this;
		}
	}

	if (mLength)
	{
		delete[] mString;
	}
	else
	{
		delete mString;
	}

	mLength = str.mLength;
	mString = new char[mLength + 1];

	for (int i = 0; i < mLength; i++)
	{
		mString[i] = str.mString[i];
	}

	mString[mLength] = '\0';

	return *this;
}

std::ostream& operator<<(std::ostream& os, String str)
{
	int i{};
	while (str[i] != '\0')
	{
		os << str[i++];
	}

	return os;
}
