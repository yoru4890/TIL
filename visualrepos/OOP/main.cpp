#include <iostream>
#include "Player.h"

class AirConditioner
{
	int mTemperature;

public:
	int GetTemperature() const
	{
		return mTemperature;
	}

};

class Calendar
{
private:
	int mMonth;

public:
	void SetMonth(std::string m)
	{
		// Dec -> 12
		mMonth = 12;
	}

	std::string GetMonth() const
	{
		// 1 - jan
		// 2 - feb

		return "januaray";

	}
};

int main()
{
	Player wolf;

	wolf.GetAttack();

	Player::Costume costume = Player::Costume::Summer;

	AirConditioner myHouse;
	myHouse.GetTemperature();

}