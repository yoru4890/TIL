#pragma once
class Stack
{
	class Element
	{
		int num;
		Element* pNext{};
	};

	Element* pTop;
	int size;

public:

	Stack();

	int Size() const;

	void Push(int num);

	void Pop();
};

