#include <iostream>

const int QUEUE_SIZE{ 10 };

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	QUIT =3
};

struct Queue
{
	int container[QUEUE_SIZE]{};
	int head{};
	int tail{};
};

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl <<
		"[2] DEQUEUE" << std::endl <<
		"[3] QUIT" << std::endl;
	std::cout << "-----------" << std::endl;
}

void PrintQueue(Queue& queue)
{
	int i = queue.head;

	if (queue.head == queue.tail)
	{
		std::cout << "Empty" << std::endl;
		return;
	}

	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.container[i] << " ";
	}

	std::cout << std::endl <<
		"-----------" << std::endl;
}

void EnQueue(Queue& queue, int value)
{
	if ((queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "QUEUE is FULL!" << std::endl;
		return;
	}

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.container[queue.tail] = value;
}

void DeQueue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "QUEUE is already EMPTY" << std::endl;
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;
}

int main()
{
	Queue myQueue;

	PrintInfo();

	int command{};
	while (true)
	{
		PrintQueue(myQueue);

		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE: 
				{
					int value;
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

			dafault:
				std::cout << "잘못된 명령입니다." << std::endl;
				break;
		}
	}
}