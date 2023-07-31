#include <iostream>
#include "Cat.h"
#include "Dog.h"

int main()
{
	Cat nabi;
	
	nabi.SetAge(2);
	nabi.SetBreed(Cat::BREED::TURKISHANGORA);
	nabi.Sound();
	nabi.Grooming();

	Dog marry;

	marry.SetAge(2);
	marry.SetBreed(Dog::BREED::JINDOTGAE);
	marry.Sound();
	marry.Bark();
}


