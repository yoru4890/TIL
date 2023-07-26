#include <iostream>

class MyClass
{
private:
    int mValue;

public:
    MyClass(int x) : mValue(x)
    {
        std::cout << "�Ϲ� ������" << std::endl;
    }

    MyClass(const MyClass& target)
    {
        mValue = target.mValue;
        std::cout << "���� ������" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "[-]" << std::endl;
    }

};



int main()
{
    MyClass c1(1);
    MyClass c2(c1);

    std::cout << "--------------------" << std::endl;

    MyClass c3(MyClass(1));

}


