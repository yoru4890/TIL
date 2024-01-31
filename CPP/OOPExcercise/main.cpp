#include <iostream>

template <typename T>
class MyClass
{
	T mValue;
	
public:
	void Function(T arg);
	
};

int main()
{
	
}

template<typename T>
void MyClass<T>::Function(T arg)
{
}
