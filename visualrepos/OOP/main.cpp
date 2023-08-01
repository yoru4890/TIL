#include <iostream>

class Parent
{
public:
	Parent();
	Parent(const Parent& from)
	{

	}

	virtual Parent* Clone();
};

class Child : public Parent
{
public:
	Child();

	Child(const Child& from)
	{

	}

	Parent* Clone() override
	{

	}
};

int main()
{
	Parent* p = new Child;

	Parent* p1(p);
}


