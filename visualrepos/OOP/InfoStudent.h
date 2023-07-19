#pragma once
#include <string>

class InfoStudent
{
	std::string mName;
	int mNum;
	int mScore;

public:
	InfoStudent();

	InfoStudent(std::string name, int num, int score);

	void InputInfo(std::string name, int num, int score);
};

