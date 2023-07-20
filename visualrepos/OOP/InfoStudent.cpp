#include <iostream>
#include "InfoStudent.h"

InfoStudent::InfoStudent() : InfoStudent("UNKNOWN", 0 , 0)
{
}

InfoStudent::InfoStudent(const char* name, int num, int score) : mName{name} , mNum{num}, mScore{score}
{
}

void InfoStudent::InputInfo(const char* name, int num, int score)
{
	mName.Strcpy(name);
	mNum = num;
	mScore = score;
}

void InfoStudent::InputInfo(String name, int num, int score)
{
	mName.Strcpy(name);
	mNum = num;
	mScore = score;
}

void InfoStudent::Sort(int studentNum)
{
	InfoStudent* p = this;

	QuickSort(p, 0, studentNum - 1);

}

void InfoStudent::Print()
{
	std::cout << mScore << " " << mNum << "¹ø ";
	mName.Print();
	
}

int InfoStudent::GetScore()
{
	return mScore;
}

void QuickSort(InfoStudent* p, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int i{ start }, j{ start };
	InfoStudent* pivot = p + end;
	
	for (; j < end; j++)
	{
		if ((p + j)->GetScore() > pivot->GetScore())
		{
			Swap(*(p + i), *(p + j));
			i++;
		}
	}

	Swap(*(p + i), *pivot);

	
	QuickSort(p, start, i - 1);

	QuickSort(p, i + 1, end);

}

void Swap(InfoStudent& a, InfoStudent& b)
{
	InfoStudent temp{ a };
	a = b;
	b = temp;
}
