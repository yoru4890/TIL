#include <iostream>

class Monster
{
private:
	const int mHealth;
	const int mLevel;

public:
	// default constructor
	/*Monster()
	{
		mHealth = 1;
		mLevel = 1;
	}*/

	Monster(int level = 0, int health = 0) : mHealth{ health }, mLevel{ level }
	{
	}

	/*Monster()
	{
		mHealth = mLevel = 0;
	}

	Monster(int level)
	{
		mLevel = level;
		mHealth = 0;
	}*/

	void Print()
	{
		std::cout << "Health : " << mHealth << std::endl;
		std::cout << "Level : " << mLevel << std::endl;
	}
};

int main()
{
	Monster m1(10, 100);

	m1.Print();

}

