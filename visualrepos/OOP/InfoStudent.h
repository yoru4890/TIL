#pragma once
#include "String.h"

class InfoStudent
{
	String mName;
	int mNum;
	int mScore;

public:
	InfoStudent();

	InfoStudent(const char* name, int num, int score);

	void InputInfo(const char* name, int num, int score);

	void InputInfo(String name, int num, int score);

	void Sort(int studentNum);

	void Print();

	int GetScore();

};

void QuickSort(InfoStudent* p, int start, int end);

void Swap(InfoStudent& a, InfoStudent& b);

