#pragma once
class String
{
	class CustomChar
	{
	public:
		char character;

		CustomChar* pNext;
	};

	int stringLength;

	CustomChar* startChar;

public:

	String();

	String(const char* str);

	void Print() const;

	int StringLength() const;

	void Strcpy(const char* str);

	void Strcpy(String& str);

	bool Strcmp(const char* str) const;

	bool Strcmp(String& str) const;

};

