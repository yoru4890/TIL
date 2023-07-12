#include <iostream>

class Galaxy
{
	// state - member variable
private:
	char modelName[10];

public:
	int color;
	int weight;

	// bahaviour - member function
	void Phone()
	{
		std::cout << "������" << std::endl;
	}
	void Message()
	{
		std::cout << "�޽���" << std::endl;
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
		std::cout << this->power << std::endl;
	}

public:

	void ShowPrice()
	{
		std::cout << this->price << std::endl;
	}

};

int main()
{
	// Instantiate (�ν��Ͻ�ȭ)
	Galaxy myPhone;

	myPhone.color = 1;
	myPhone.Phone();

	Galaxy yourPhone;
	yourPhone.color = 2;
}