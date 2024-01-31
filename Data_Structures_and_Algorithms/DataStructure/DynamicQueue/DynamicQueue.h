#pragma once

#include "Queue.h"

struct QueueList
{
	Queue* pHead{};
	Queue* pTail{};
};

void EnQueue(QueueList& list, const int num);

void DeQueue(QueueList& list);

void PrintQueue(QueueList& list);

void PrintQueueR(Queue* p);