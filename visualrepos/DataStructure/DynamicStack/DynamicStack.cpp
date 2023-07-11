#include <iostream>
#include "DynamicStack.h"

void Push(StackList& list, const int num)
{
	Stack* element = new Stack;

	element->num = num;

	if (list.pHead)
	{
		element->pNext = list.pHead;
	}
	else
	{
		list.pTail = element;
	}

	list.pHead = element;
}

void Pop(StackList& list)
{
	Stack* p = list.pHead;

	if (list.pHead == list.pTail && p)
	{
		list.pHead = list.pTail = nullptr;
		delete p;
		return;
	}
	else if (p)
	{
		list.pHead = p->pNext;

		delete p;

		return;
	}
	
	std::cout << "뺄게 없습니다" << std::endl;

}

void PrintStack(StackList& list)
{
	Stack* p = list.pHead;

	while (p)
	{
		std::cout << p->num << std::endl;
		p = p->pNext;
	}

}

void PrintStackR(Stack* p)
{
	if (!p)
	{
		return;
	}

	std::cout << p->num << std::endl;

	p = p->pNext;

	PrintStackR(p);

}

