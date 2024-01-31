#pragma once
#include "LinkedList.h"
class Queue : public LinkedList
{
private:
	Element* mpFirst;
	Element* mpEnd;

public:
	Queue();

	Queue(const Queue& queue);

	~Queue();

	void Insert(int num) override;

	void Erase() override;

	void Print() override;

	void DeleteAll() override;

	LinkedList* Clone() override;

	LinkedList::Element* First();
};

