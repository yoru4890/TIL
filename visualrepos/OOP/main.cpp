#include <iostream>
#include "Stack.h"

int main()
{
	Stack myStack{};

	myStack.Push(2);
	myStack.Push(3);
	myStack.Push(4);
	myStack.Push(5);
	myStack.Push(6);
	myStack.Print();
	myStack.Pop();
	myStack.Pop();
	myStack.Print();
	std::cout << myStack.Size() << std::endl;
	std::cout << myStack.Top()->num << std::endl;
}



