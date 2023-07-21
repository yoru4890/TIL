#pragma once
class Queue
{
	class Element
	{
	public:
		int mNum{};
		Element* mPNext{};
	};

	Element* mPFirst;
	Element* mPEnd;
	int mSize;

public:

	Queue();

	~Queue();

	int Size() const;

	void EnQueue(int num);

	void DeQueue();

	void Print() const;

	Element* First() const;
};

