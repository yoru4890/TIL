#include <iostream>

const int QUEUE_SIZE{ 10 };

struct Queue
{
	int array[QUEUE_SIZE];
	int head{};
	int tail{};
};

enum command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	QUIT = 3
};

void PrintInfo();

void PrintQueue(Queue& queue);

void EnQueue(Queue& queue, int value);

void DeQueue(Queue& queue);

int main()
{
	int command{};

	Queue myQueue{};

	PrintInfo();

	while (true)
	{
		PrintQueue(myQueue);

		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
				{
					int value{};
					std::cout << "\tvalue : ";
					std::cin >> value;
					EnQueue(myQueue, value);					
				}
				break;
				
			case DEQUEUE:
				DeQueue(myQueue);
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
	std::cout << "1. EnQueue" << std::endl << "2. DeQueue" << std::endl << "3. Quit" << std::endl;
}

void PrintQueue(Queue& queue)
{
	int i = queue.head;
	if (queue.head == queue.tail)
	{
		std::cout << "------------" << std::endl;
		std::cout << "비어 있습니다" << std::endl;
		std::cout << "------------" << std::endl;
		return;
	}

	std::cout << "------------" << std::endl;

	while(i!=queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.array[i] << " ";
	}
	std::cout << std::endl 
		<< "------------" << std::endl;
}

void EnQueue(Queue& queue, int value)
{
	if ((queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "꽉 찼습니다" << std::endl;
		return;
	}

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.array[queue.tail] = value;
}

void DeQueue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "더이상 뺼 수 없습니다" << std::endl;
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;
}