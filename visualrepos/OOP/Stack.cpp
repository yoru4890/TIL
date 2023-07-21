#include <iostream>
#include "Stack.h"

Stack::Stack() : mPTop{ nullptr }, mSize{}
{
}

Stack::~Stack()
{
	Element* p{ mPTop };
	Element* pNext;

	while (p)
	{
		pNext = p->mPNext;
		delete p;
		p = pNext;
	}
	
}

int Stack::Size() const
{
	return mSize;
}

void Stack::Push(int num)
{
	Element* pElement = new Element;
	pElement->mNum = num;
	pElement->mPNext = mPTop;

	mPTop = pElement;
	mSize++;

}

void Stack::Pop()
{
	Element* p{ mPTop };
	Element* pNext;

	if (!p)
	{
		std::cout << "더이상 뺄게 없습니다." << std::endl;
		return;
	}

	pNext = p->mPNext;
	delete p;

	mPTop = pNext;
	mSize--;
}

void Stack::Print() const
{
	Element* p{ mPTop };

	while (p)
	{
		std::cout << p->mNum << std::endl;
		p = p->mPNext;
	}
}

Stack::Element* Stack::Top() const
{
	return mPTop;
}