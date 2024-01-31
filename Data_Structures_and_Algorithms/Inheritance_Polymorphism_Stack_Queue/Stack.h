#pragma once
#include "LinkedList.h"
class Stack : public LinkedList
{
private:
	Element* mpHead;

public:
	Stack();

	Stack(const Stack& stack);

	~Stack();

	void Insert(int num) override;

	void Erase() override;

	void Print() override;

	void DeleteAll() override;

	LinkedList* Clone() override;

	LinkedList::Element* Head();

};

