#pragma once
class Date
{
	int mYear;
	int mMonth;
	int mDay;
	int mMonthDay[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

public:
	bool IsLeapYear;

	Date();

	Date(int year, int month, int day);

	void SetDate(int year, int month, int day);

	void PrintDate() const;

	void DdayCaculator(int year, int month, int day) const;

	void DayAfter(int day);

};