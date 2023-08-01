#pragma once
class Animal
{
protected:
	int mAge;
	int mWeight;

public:
	Animal();
	Animal(int age, int weight);
	virtual ~Animal();

	int GetAge() const;
	int GetWeight() const;
	void SetAge(int age);
	void SetWeight(int weight);

	void Sound();
};

