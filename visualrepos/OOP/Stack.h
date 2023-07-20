#pragma once

class Element
{
public:
	int num{};
	Element* pNext{};
};

class Stack
{
	
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

