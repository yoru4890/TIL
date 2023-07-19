#include "InfoStudent.h"

InfoStudent::InfoStudent() : InfoStudent("UNKNOWN", 0 , 0)
{
}

InfoStudent::InfoStudent(std::string name, int num, int score) : mName{name} , mNum{num}, mScore{score}
{
}

void InfoStudent::InputInfo(std::string name, int num, int score)
{
	mName = name;
	mNum = num;
	mScore = score;
}
