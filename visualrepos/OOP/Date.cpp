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
		std::cout << "���� ���� ������ ��¥�� �ùٸ� ��¥�� �ƴմϴ�. ���� �Է��ؼ� �ùٸ� ��¥�� �Ͻô°� ��õ�帳�ϴ�." << std::endl;
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
		std::cout << "���� ���� ����� ��¥�� �ùٸ� ��¥�� �ƴմϴ�. ���� �Է��ؼ� �ùٸ� ��¥�� �Ͻô°� ��õ�帳�ϴ�." << std::endl;
	}
	
	mYear = year;
	mMonth = month;
	mDay = day;
}

void Date::PrintDate() const
{
	std::cout << mYear << "�� " << mMonth << "�� " << mDay << " ��" << std::endl;
}

void Date::DdayCaculator(int year, int month, int day) const
{
	int dDay{};
	int countYear = mYear;
	int countMonth = mMonth;
	bool IsLeapCountYear{};


	if (year < mYear || year == mYear && month < mMonth || year == mYear && month == mMonth && day < mDay)
	{
		std::cout << "���� ���� �Է��Ͻ� ��¥�� D-Day ����ϱ⿡ �������� �ʽ��ϴ�. ���� �Է����ּ���." << std::endl;
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

	std::cout << "D-" << dDay << "�Դϴ�." << std::endl;

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
