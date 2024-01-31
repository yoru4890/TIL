#include <iostream>
#include "Player.h"

void Player::Walk()
{
	std::cout << "Walk" << std::endl;
}

void Player::Run()
{
	Sword s1;
	Costume costume = Summer;

	std::cout << "Run" << std::endl;
}

void Player::Jump()
{
	std::cout << "Jump" << std::endl;
}
