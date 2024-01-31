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
	CustomChar* endChar;

public:

	String();

	String(const char* str);

	~String();

	void Print() const;

	int StringLength() const;

	void Strcpy(const char* str);

	bool Strcmp(const char* str) const;

	void AddStr(const char* str);
};

