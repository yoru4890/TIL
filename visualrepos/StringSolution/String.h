#pragma once
class String
{
	char* mString;
	int mLength;

public:

	String();

	String(int size);

	String(const char* str);

	String(const String& str);

	~String();

	String* Print();

	int Length();

	String operator + (const String& str) const;

	String& operator += (const String& str);

	char& operator [] (int index);

	String& operator = (const String& str);

	friend std::ostream& operator << (std::ostream& os, String str);
};



