#include <iostream>
#include "DynamicQueue.h"

int main()
{
	enum { ENQUEUE, DEQUEUE, QUIT };
	QueueList myList;

	int control{};
	int inputNum{};

	while (true)
	{
		std::cout << "0. ENQUEUE\n1. DEQUEUE\n2. QUIT\n";

		std::cin >> control;

		switch (control)
		{
			case ENQUEUE:
				std::cout << ">";
				std::cin >> inputNum;
				EnQueue(myList, inputNum);
				std::cout << "------------" << std::endl;
				PrintQueue(myList);
				std::cout << std::endl<<"------------" << std::endl;
				break;

			case DEQUEUE:
				DeQueue(myList);
				std::cout << "------------" << std::endl;
				PrintQueue(myList);
				std::cout <<std::endl<< "------------" << std::endl;
				break;

			case QUIT:
				return 0;
				break;

			default:
				std::cout << "잘못된 입력입니다" << std::endl;
				break;
		}
	}
}