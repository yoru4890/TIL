#pragma once
class Stack
{
	class Element
	{
	public:
		int mNum{};
		Element* mPNext{};
	};

	Element* mPTop;
	int mSize;

public:

	Stack();

	~Stack();

	int Size() const;

	void Push(int num);

	void Pop();
	
	void Print() const;

	Element* Top() const;
};

