#include <iostream>
#include "Queue.h"

Queue::Queue() : mpFirst{ nullptr }, mpEnd{ nullptr }
{
}

Queue::Queue(const Queue& queue)
{
	mSize = queue.mSize;
	Element* p = queue.mpFirst;

	Element* pElement = new Element;
	Element* pPre;
	pElement->num = p->num;
	mpFirst = pElement;

	for (int i = 0; i < mSize - 1; i++)
	{
		p = p->pNext;
		pPre = pElement;
		pElement = new Element;
		pElement->num = p->num;
		pPre->pNext = pElement;
	}

	pElement->pNext = nullptr;
	mpEnd = pElement;
}

Queue::~Queue()
{
	Element* p = mpFirst;
	Element* pNext;

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}
}

void Queue::Insert(int num)
{
	mSize++;
	Element* pElemnet = new Element;
	pElemnet->num = num;
	pElemnet->pNext = nullptr;

	if (!mpFirst)
	{
		mpFirst = pElemnet;
	}
	else
	{
		mpEnd->pNext = pElemnet;
	}

	mpEnd = pElemnet;

}

void Queue::Erase()
{
	Element* p = mpFirst;
	Element* pNext;

	if (!p)
	{
		std::cout << "Empty" << std::endl;
		return;
	}

	pNext = p->pNext;
	delete p;
	mpFirst = pNext;
	mSize--;
}

void Queue::Print()
{
	Element* p = mpFirst;

	while (p)
	{
		std::cout << p->num << " ";
		p = p->pNext;
	}

	std::cout << std::endl;
}

void Queue::DeleteAll()
{
	Element* p = mpFirst;
	Element* pNext;

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}

	mpFirst = mpEnd = nullptr;

	mSize = 0;
}

LinkedList* Queue::Clone()
{
	return new Queue(*this);
}

LinkedList::Element* Queue::First()
{
	return mpFirst;
}
