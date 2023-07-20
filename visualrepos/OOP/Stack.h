#pragma once
class Stack
{
	class Element
	{
	public:
		int num{};
		Element* pNext{};
	};

	Element* pTop;
	int size;

public:

	Stack();

	~Stack();

	int Size() const;

	void Push(int num);

	void Pop();
	
	void Print() const;

	Element* Top() const;
};

