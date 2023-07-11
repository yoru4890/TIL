#pragma once

#include "Monster.h"

struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

// Create
Monster* CreateMonster(MonsterList& list, const char* name, const int hp);

// Count
int GetMonsterCount(const MonsterList& list);

// Print

void PrintMonsters(const MonsterList& list);
void PrintMonstersR(Monster* pMonster);

// Search

Monster* FindMonster(const MonsterList& list, const char* name);

// Delete All
void DeleteAll(MonsterList& list);

// Delete Element
bool DeleteMonster(MonsterList& list, const char* name);