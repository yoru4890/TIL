#include <iostream>
#include "SingleLinkedList.h"

int main()
{
	MonsterList myList;

	CreateMonster(myList, "Demon", 100);
	CreateMonster(myList, "Wolf", 50);
	CreateMonster(myList, "Slime", 10);

	PrintMonsters(myList);
	PrintMonstersR(myList.pHead);
	std::cout << GetMonsterCount(myList) << std::endl;

	Monster* pResult = FindMonster(myList, "Demon");
	if (pResult)
	{
		std::cout << pResult->name << "Found!" << std::endl;
	}
	else
	{
		std::cout << "Not Found!" << std::endl;
	}

	DeleteAll(myList);
}