#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	enum BREED
	{
		RETRIEVER, HUSKY, SHIBA, JINDOTGAE
	};

private:
	BREED mBreed;

public:
	Dog();
	~Dog();

	Dog::BREED GetBreed() const;
	void SetBreed(Dog::BREED breed);

	void Bark();

};

