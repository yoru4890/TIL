#include <iostream>

const int STACK_SIZE{ 10 };

struct Stack
{
	int array[STACK_SIZE];
	int topIndex{ -1 };
};

enum Command
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};

void PrintInfo();

void PrintStack(Stack& stack);

void Push(Stack& stack, int value);

void Pop(Stack& stack);

int main()
{
	int command{};

	Stack myStack{};

	PrintInfo();

	while (true)
	{
		PrintStack(myStack);
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
				{
					int value{};
					std::cout << "\tvalue : ";
					std::cin >> value;
					Push(myStack, value);
				}
				break;

			case POP:
				Pop(myStack);
				break;

			case QUIT:
				return 0;
				break;

			default:
				std::cout << "잘못된 입력입니다." << std::endl;
				break;
		}
	}
}

void PrintInfo()
{
	std::cout << "1. Push" << std::endl << "2. Pop" << std::endl << "3. Quit" << std::endl;
}

void PrintStack(Stack& stack)
{
	if (stack.topIndex <= -1)
	{
		std::cout << "----------------" << std::endl;
		std::cout << "비어 있습니다." << std::endl;
		std::cout << "----------------" << std::endl;
		return;
	}

	std::cout << "----------------" << std::endl;

	for (int i = stack.topIndex; i >= 0; i--)
	{
		std::cout << stack.array[i] << std::endl;
	}

	std::cout << "----------------" << std::endl;
}

void Push(Stack& stack, int value)
{
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "꽉 찼습니다" << std::endl;
		return;
	}

	stack.array[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{
	if (stack.topIndex <= -1)
	{
		std::cout << "더 뺼수 없습니다." << std::endl;
		return;
	}

	stack.topIndex--;
}