#include <iostream>
#include "DynamicStack.h"

void Push(Stack& stack, const int num)
{
	Element* pElement = new Element;

	pElement->num = num;

	pElement->pNext = stack.pTop;
	stack.pTop = pElement;
	stack.count++;

}

void Pop(Stack& stack)
{
	if (stack.count == 0)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return;
	}

	Element* pPrevTop = stack.pTop;

	stack.pTop = pPrevTop->pNext;
	stack.count--;
	
	delete pPrevTop;

}

void PrintStack(Stack& stack)
{
	Element* p = stack.pTop;

	while (p)
	{
		std::cout << p->num << std::endl;
		p = p->pNext;
	}

}

void PrintStackR(Element* p)
{
	if (!p)
	{
		return;
	}

	std::cout << p->num << std::endl;

	p = p->pNext;

	PrintStackR(p);

}

void DeleteAll(Stack& stack)
{
	Element* pElement = stack.pTop;
	Element* pNext{};

	while (pElement)
	{
		pNext = pElement->pNext;
		delete pElement;
		pElement = pNext;
	}

	stack.count = 0;
	stack.pTop = nullptr;
}

