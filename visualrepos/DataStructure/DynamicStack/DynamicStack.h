#pragma once

#include "Stack.h"

struct StackList
{
	Stack* pHead{};
	Stack* pTail{};
};

void Push(StackList& list, const int num);

void Pop(StackList& list);

void PrintStack(StackList& list);

void PrintStackR(Stack* p);