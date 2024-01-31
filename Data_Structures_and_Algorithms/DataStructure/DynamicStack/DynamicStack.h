#pragma once

#include "Stack.h"

struct Stack
{
	int count{};
	Element* pTop{};
};

void Push(Stack& stack, const int num);

void Pop(Stack& stack);

void PrintStack(Stack& stack);

void PrintStackR(Element* p);

void DeleteAll(Stack& stack);