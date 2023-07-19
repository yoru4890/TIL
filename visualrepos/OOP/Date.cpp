#include <iostream>
#include "Date.h"

Date::Date() : Date(1, 1, 1)
{
	IsLeapYear = false;
}

Date::Date(int year, int month, int day) : mYear{year}, mMonth{month}, mDay{day}
{
	if ((mYear % 4 == 0 && mYear % 100 != 0) || mYear % 400 == 0)
	{
		IsLeapYear = true;
	}
	else
	{
		IsLeapYear = false;
	}

	if (year < 0 || month>12 || month < 0 || day < 0 || (day > mMonthDay[month - 1] && !IsLeapYear) || (day > 29 && month == 2 && IsLeapYear))
	{
		std::cout << "지금 현재 생성된 날짜는 올바른 날짜가 아닙니다. 새로 입력해서 올바른 날짜로 하시는걸 추천드립니다." << std::endl;
	}
}

void Date::SetDate(int year, int month, int day)
{
	if ((mYear % 4 == 0 && mYear % 100 != 0) || mYear % 400 == 0)
	{
		IsLeapYear = true;
	}
	else
	{
		IsLeapYear = false;
	}

	if (year < 0 || month>12 || month < 0 || day < 0 || (day > mMonthDay[month - 1] && !IsLeapYear) || (day > 29 && month == 2 && IsLeapYear))
	{
		std::cout << "지금 현재 저장된 날짜는 올바른 날짜가 아닙니다. 새로 입력해서 올바른 날짜로 하시는걸 추천드립니다." << std::endl;
	}
	
	mYear = year;
	mMonth = month;
	mDay = day;
}

void Date::PrintDate() const
{
	std::cout << mYear << "년 " << mMonth << "월 " << mDay << " 일" << std::endl;
}

void Date::DdayCaculator(int year, int month, int day) const
{
	int dDay{};
	int countYear = mYear;
	int countMonth = mMonth;
	bool IsLeapCountYear{};


	if (year < mYear || year == mYear && month < mMonth || year == mYear && month == mMonth && day < mDay)
	{
		std::cout << "지급 현재 입력하신 날짜는 D-Day 계산하기에 적합하지 않습니다. 새로 입력해주세요." << std::endl;
		return;
	}

	if (month < mMonth)
	{
		countMonth += 12;
		countYear++;
		if ((countYear % 4 == 0 && countYear % 100 != 0) || countYear % 400 == 0)
		{
			IsLeapCountYear = true;
		}
	}

	while (month % 12 != countMonth % 12)
	{
		if (countMonth % 12 != 0)
		{
			dDay += mMonthDay[countMonth % 12 - 1];
			if (IsLeapCountYear && countMonth % 12 == 2)
			{
				dDay++;
			}
		}
		else
		{
			dDay += mMonthDay[11];
		}
		
		countMonth++;
	}

	while (year > countYear)
	{
		dDay += 365;
		countYear++;
		if ((countYear % 4 == 0 && countYear % 100 != 0) || countYear % 400 == 0)
		{
			day++;
		}
		
	}

	dDay += day - mDay;

	std::cout << "D-" << dDay << "입니다." << std::endl;

}

void Date::DayAfter(int day)
{
	mDay += day;

	while (mDay >= 365)
	{
		mYear++;

		if ((mYear % 4 == 0 && mYear % 100 != 0) || mYear % 400 == 0)
		{
			mDay -= 366;
		}
		else
		{
			mDay -= 365;
		}
	}

	if ((mYear % 4 == 0 &&  mYear % 100 != 0) || mYear % 400 == 0)
	{
		IsLeapYear = true;
	}
	else
	{
		IsLeapYear = false;
	}

	while (mDay > mMonthDay[mMonth - 1]|| mDay > 29 && mMonth == 2 && IsLeapYear)
	{
		if (IsLeapYear && mMonth == 2)
		{
			mDay -= 29;
		}
		else
		{
			mDay -= mMonthDay[mMonth - 1];
		}

		mMonth++;

		if (mMonth > 12)
		{
			mMonth = 1;
			mYear++;

			if ((mYear % 4 == 0 && mYear % 100 != 0) || mYear % 400 == 0)
			{
				IsLeapYear = true;
			}
			else
			{
				IsLeapYear = false;
			}
		}
	}

	PrintDate();
}
