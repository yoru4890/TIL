#include "LinkedList.h"

LinkedList::LinkedList() : mSize{}
{
}

LinkedList::~LinkedList()
{
}

void LinkedList::Insert(int num)
{
}

void LinkedList::Erase()
{
}

void LinkedList::Print()
{
}

void LinkedList::DeleteAll()
{
}

LinkedList* LinkedList::Clone()
{
	return new LinkedList(*this);
}

int LinkedList::Size()
{
	return mSize;
}
