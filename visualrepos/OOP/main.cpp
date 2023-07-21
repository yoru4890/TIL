#include <iostream>
#include "Stack.h"

int main()
{
	Stack myStack;
	std::cout << myStack.Size() << std::endl;
	myStack.Print();
	std::cout << "-------------------" << std::endl;
	myStack.Push(2);
	std::cout << myStack.Size() << std::endl;
	myStack.Print();
	std::cout << "-------------------" << std::endl;
	myStack.Push(3);
	myStack.Push(10);
	myStack.Push(5);
	myStack.Push(4);
	std::cout << myStack.Size() << std::endl;
	myStack.Print();
	std::cout << "-------------------" << std::endl;
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	std::cout << myStack.Size() << std::endl;
	myStack.Print();
	std::cout << "-------------------" << std::endl;
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	std::cout << myStack.Size() << std::endl;
	myStack.Push(4);
	std::cout << myStack.Size() << std::endl;
	myStack.Push(5);
	myStack.Print();
	std::cout << myStack.Top()->mNum;


}



