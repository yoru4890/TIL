#include <iostream>

class Sword; // forward declaration

class Player
{
public:
	void AttackWith(Sword& sword);
	void A();

};

class Sword
{
	friend void Player::AttackWith(Sword& sword);

private:
	int mDamage;

public:
	Sword(int dmg) : mDamage{ dmg } {}
};

// 선언과 정의 분리
void Player::AttackWith(Sword& sword)
{
	std::cout << "칼을 휘둘러" << sword.mDamage << "만큼 피해를 주었다!" << std::endl;
}


int main()
{
	Sword muramasa{ 10 };

	Player p1;

	p1.AttackWith(muramasa);

}


