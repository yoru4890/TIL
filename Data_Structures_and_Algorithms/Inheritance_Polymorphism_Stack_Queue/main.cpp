#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
	LinkedList* stackList = new Stack;
	LinkedList* queueList = new Queue;

	queueList->Insert(1);
	queueList->Insert(2);
	queueList->Insert(3);
	queueList->Insert(4);

	LinkedList* p(queueList->Clone());

	p->Print();

	queueList->DeleteAll();

	p->Print();

	p->Insert(100);

	p->Print();

	std::cout << queueList->Size();
}
