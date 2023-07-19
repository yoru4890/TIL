#pragma once
class String
{
	class CustomChar
	{
	public:
		char character;

		CustomChar* pNext;
	};

	CustomChar* startChar;
	CustomChar* endChar;
	int stringLength;

	String();

	String(const char str[12]);

	void Print() const;
};

