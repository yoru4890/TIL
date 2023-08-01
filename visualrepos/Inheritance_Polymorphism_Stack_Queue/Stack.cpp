#include <iostream>
#include "Stack.h"

Stack::Stack() : mpHead{nullptr}
{
}

Stack::Stack(const Stack& stack)
{
	mSize = stack.mSize;
	Element* p = stack.mpHead;

	Element* pElement = new Element;
	Element* pPre;
	pElement->num = p->num;
	mpHead = pElement;

	for (int i = 0; i < mSize-1; i++)
	{
		p = p->pNext;
		pPre = pElement;
		pElement = new Element;
		pElement->num = p->num;
		pPre->pNext = pElement;
	}

	pElement->pNext = nullptr;

}

Stack::~Stack()
{
	Element* p = mpHead;
	Element* pNext;

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}
}

void Stack::Insert(int num)
{
	Element* pElement = new Element;
	pElement->num = num;

	pElement->pNext = mpHead;
	mpHead = pElement;
	mSize++;
}

void Stack::Erase()
{
	Element* p = mpHead;
	Element* pNext;

	if (!p)
	{
		std::cout << "Empty" << std::endl;
		return;
	}

	pNext = p->pNext;
	delete p;
	mpHead = pNext;
	mSize--;
}

void Stack::Print()
{
	Element* p = mpHead;

	while (p)
	{
		std::cout << p->num << std::endl;
		p = p->pNext;
	}
}

void Stack::DeleteAll()
{
	Element* p = mpHead;
	Element* pNext;

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}

	mpHead = nullptr;

	mSize = 0;
}

LinkedList* Stack::Clone()
{
	return new Stack(*this);
}

LinkedList::Element* Stack::Head()
{
	return mpHead;
}
