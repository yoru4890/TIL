#include <iostream>
#include "DynamicStack.h"

int main()
{
	enum{PUSH, POP, QUIT};
	Stack myStack;

	int control{};
	int inputNum{};

	while (true)
	{
		std::cout << "0. PUSH"<<std::endl<<"1. POP"<<std::endl<<"2. QUIT"<<std::endl;

		std::cin >> control;

		switch (control)
		{
			case PUSH:
				std::cout << ">";
				std::cin >> inputNum;
				Push(myStack, inputNum);
				std::cout << "------------" << std::endl;
				PrintStack(myStack);
				std::cout << "------------" << std::endl;
				break;
			case POP:
				Pop(myStack);
				std::cout << "------------" << std::endl;
				PrintStackR(myStack.pHead);
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