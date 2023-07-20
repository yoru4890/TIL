#include <iostream>
#include "Stack.h"

Stack::Stack() : pTop{ nullptr }, size{}
{
}

Stack::~Stack()
{
}

int Stack::Size() const
{
	return size;
}

void Stack::Push(int num)
{
	Element* pElement = new Element;
	pElement->num = num;
	pElement->pNext = pTop;

	pTop = pElement;
	size++;

}

void Stack::Pop()
{
	Element* p{ pTop };
	Element* pNext{ p->pNext };

	delete p;

	pTop = pNext;
	size--;
}

void Stack::Print() const
{
	Element* p{ pTop };

	while (p)
	{
		std::cout << p->num << std::endl;
		p = p->pNext;
	}
}

Stack::Element* Stack::Top() const
{
	return pTop;
}