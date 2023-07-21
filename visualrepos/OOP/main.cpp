#include <iostream>
#include "Queue.h"

int main()
{
	Queue myQueue;

	myQueue.EnQueue(10);
	std::cout << myQueue.Size() << std::endl;
	myQueue.EnQueue(20);
	std::cout << myQueue.Size() << std::endl;
	myQueue.Print();
	myQueue.DeQueue();
	std::cout << std::endl;
	myQueue.Print();
	std::cout << myQueue.Size() << std::endl;
	myQueue.DeQueue();
	myQueue.DeQueue();
	std::cout << myQueue.Size() << std::endl;
	myQueue.EnQueue(100);
	std::cout << myQueue.First()->mNum << std::endl;

}



