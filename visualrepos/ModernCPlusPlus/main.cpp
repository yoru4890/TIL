#include <iostream>

class Warrior
{
public:
	int mHealth;
	int mAttack;

	Warrior(int h, int a) : mHealth{ h }, mAttack{ a }
	{
	}
};

int main()
{
	std::unique_ptr<Warrior> spWarrior = std::make_unique<Warrior>(100, 20);

	std::cout << spWarrior->mAttack << std::endl;

	spWarrior.release();	// delete p;
	spWarrior.reset();		// delete p; p = nullptr;

	Warrior* ptr = spWarrior.get();	// 일반 포인터
}

