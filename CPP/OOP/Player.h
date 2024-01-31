#pragma once

class Player
{
public:
	class Sword
	{
		int mPrice;
		int mAttack;
	};

	enum Costume
	{
		Hunter = 1,
		Summer = 2,
		Winter = 3
	};

private:
	int mHealth;
	int mAttack;

public:
	void Walk();
	void Run();
	void Jump();
	int GetAttack()
	{
		if (mAttack < 0)
		{
			std::cerr << "Somthing Wrong!" << std::endl;
		}

		// 레벨 보정 + 장비 보정
		int factor = 1;

		return mAttack = factor;
	}
};

class Computer
{

public:
	int price;
	int color;

private:
	int power;
	char mainboardName[10];

	void ShowPower()
	{
		std::cout << power << std::endl;
	}

public:

	void ShowPrice()
	{
		std::cout << price << std::endl;
	}

};


