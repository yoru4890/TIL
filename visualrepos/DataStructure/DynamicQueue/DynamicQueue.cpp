#include <iostream>
#include "DynamicQueue.h"

void EnQueue(QueueList& list, const int num)
{
	Queue* element = new Queue;

	element->num = num;

	if (list.pHead)
	{
		list.pTail->pNext = element;
		element->pPre = list.pTail;
	}
	else
	{
		list.pHead = element;
	}

	list.pTail = element;

}

void DeQueue(QueueList& list)
{
	Queue* p = list.pHead;

	if (list.pHead == list.pTail && p)
	{
		list.pHead = list.pTail = nullptr;
		delete p;
		return;
	}
	else if (p)
	{
		list.pHead = p->pNext;
		list.pHead->pPre = nullptr;
		delete p;
		return;
	}

	std::cout << "뺄게 없습니다." << std::endl;

}

void PrintQueue(QueueList& list)
{
	Queue* p = list.pHead;

	while (p)
	{
		std::cout << p->num << " ";
		p = p->pNext;
	}

}

void PrintQueueR(Queue* p)
{
	if (!p)
	{
		return;
	}

	std::cout << p->num << " ";

	p = p->pNext;

	PrintQueueR(p);
}
