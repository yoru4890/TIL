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

// ����� ���� �и�
void Player::AttackWith(Sword& sword)
{
	std::cout << "Į�� �ֵѷ�" << sword.mDamage << "��ŭ ���ظ� �־���!" << std::endl;
}


int main()
{
	Sword muramasa{ 10 };

	Player p1;

	p1.AttackWith(muramasa);

}


