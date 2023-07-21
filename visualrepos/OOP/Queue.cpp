#include <iostream>
#include "Queue.h"

Queue::Queue() : mPFirst{ nullptr }, mPEnd{ nullptr }, mSize {}
{
}

Queue::~Queue()
{
	Element* p{ mPFirst };
	Element* pNext;

	while (p)
	{
		pNext = p->mPNext;
		delete p;
		p = pNext;
	}
}

int Queue::Size() const
{
	return mSize;
}

void Queue::EnQueue(int num)
{
	Element* pElement = new Element;
	pElement->mNum = num;

	if (!mPFirst)
	{
		mPFirst = mPEnd = pElement;
		pElement->mPNext = nullptr;
		mSize++;
		return;
	}

	mPEnd->mPNext = pElement;
	mPEnd = pElement;
	mSize++;

}

void Queue::DeQueue()
{
	Element* p{ mPFirst };
	Element* pNext;

	if (!p)
	{
		std::cout << "더이상 뺄게 없습니다." << std::endl;
		return;
	}

	pNext = p->mPNext;
	delete p;
	mPFirst = pNext;
	mSize--;
}

void Queue::Print() const
{
	Element* p{ mPFirst };

	while (p)
	{
		std::cout << p->mNum << " ";
		p = p->mPNext;
	}
}

Queue::Element* Queue::First() const
{
	return mPFirst;
}
