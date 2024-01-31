#include <iostream>
#include "DoubleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* element = new Monster;

	strcpy_s(element->name, NAME_LENGTH, name);
	element->hp = hp;

	if (list.pHead)
	{
		list.pTail->pNext = element;
		element->pPrevious = list.pTail;

		list.pTail = element;
	}
	else
	{
		list.pHead = element;
		list.pTail = element;
	}

	return list.pTail;
}

int GetMonsterCount(const MonsterList& list)
{
	Monster* p = list.pHead;
	int count{};

	while (p)
	{
		count++;
		p = p->pNext;
	}

	return count;
}


void PrintMonsters(const MonsterList& list)
{
	Monster* p = list.pHead;

	while (p)
	{
		std::cout << p->name << " : " << p->hp << std::endl;
		p = p->pNext;
	}
}

void PrintMonstersR(Monster* pMonster)
{
	if (!pMonster)
	{
		return;
	}

	std::cout << pMonster->name << " : " << pMonster->hp << std::endl;

	pMonster = pMonster->pNext;

	PrintMonstersR(pMonster);
}


Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* p = list.pHead;

	while (p)
	{
		if (!strcmp(p->name, name))
		{
			return p;
		}

		p = p->pNext;
	}

	return nullptr;
}

void DeleteAll(MonsterList& list)
{
	Monster* p = list.pHead;
	Monster* pNext{};

	while (p)
	{
		pNext = p->pNext;
		delete p;
		p = pNext;
	}

	list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
	Monster* p = FindMonster(list, name);

	if (p)
	{
		if (p->pPrevious)
		{
			p->pPrevious->pNext = p->pNext;
		}
		else
		{
			list.pHead = p->pNext;
		}

		if (p->pNext)
		{
			p->pNext->pPrevious = p->pPrevious;
		}
		else
		{
			list.pTail = p->pPrevious;
		}

		delete p;

		return true;
	}

	return false;
}