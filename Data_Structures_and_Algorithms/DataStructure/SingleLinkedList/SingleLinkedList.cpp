#include <iostream>
#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* element = new Monster;

    strcpy_s(element->name, NAME_LENGTH, name);
    element->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = element;
    }
    else
    {
        list.pTail->pNext = element;
    }

    list.pTail = element;
    
    return element;
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
        std::cout <<  p->name << " : " << p->hp << std::endl;
        p = p->pNext;
    }
}

void PrintMonstersR(Monster* pMonster)
{
    if (pMonster == nullptr)
    {
        return;
    }

    std::cout << pMonster->name << " : " << pMonster->hp << std::endl;

    PrintMonstersR(pMonster->pNext);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
    Monster* p = list.pHead;

    while (p)
    {
        if (strcmp(p->name, name) == 0)
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

    while (p != nullptr)
    {
        pNext = p -> pNext;
        delete p;

        p = pNext;
    }

    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    Monster* pElement = list.pHead;
    Monster* pPrevious{};

    while (pElement)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            break;
        }

        pPrevious = pElement;
        pElement = pElement->pNext;
    }

    if (!pElement)
    {
        return false;
    }

    if (list.pHead == list.pTail)
    {
        list.pHead = list.pTail = nullptr;
    }
    else if (pPrevious == nullptr)
    {
        list.pHead = pElement->pNext;
    }
    else if (pElement == list.pTail)
    {
        list.pTail = pPrevious;
        pPrevious->pNext = nullptr;
    }
    else
    {
        pPrevious->pNext = pElement->pNext;
    }

    delete pElement;

    return true;

}
