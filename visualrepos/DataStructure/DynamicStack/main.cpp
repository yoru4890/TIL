#include <iostream>
#include "DynamicStack.h"

int main()
{
	enum{PUSH, POP, QUIT};
	StackList myList;

	int control{};
	int inputNum{};

	while (true)
	{
		std::cout << "0. PUSH\n1. POP\n2. QUIT\n";

		std::cin >> control;

		switch (control)
		{
			case PUSH:
				std::cout << ">";
				std::cin >> inputNum;
				Push(myList, inputNum);
				std::cout << "------------" << std::endl;
				PrintStack(myList);
				std::cout << "------------" << std::endl;
				break;
			case POP:
				Pop(myList);
				std::cout << "------------" << std::endl;
				PrintStackR(myList.pHead);
				std::cout << "------------" << std::endl;
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