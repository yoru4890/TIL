#pragma once
class LinkedList
{
protected:
	struct Element
	{
		int num;
		Element* pNext;
	};

	int mSize;

public:
	LinkedList();

	virtual ~LinkedList();

	virtual void Insert(int num);

	virtual void Erase();

	virtual void Print();

	virtual void DeleteAll();

	virtual LinkedList* Clone();

	int Size();

};

