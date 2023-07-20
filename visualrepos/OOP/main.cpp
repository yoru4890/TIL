#include <iostream>
#include "String.h"

int main()
{
	String s1{ "Hello World" };
	s1.Print();
	std::cout << std::endl;
	std::cout << s1.StringLength() << std::endl;
	s1.Strcpy("No");
	s1.Print();
	s1.Strcpy("YesYes");
	s1.Print();
	std::cout << std::endl;
	std::cout <<s1.Strcmp("YesYessss");
	s1.AddStr("123");
	std::cout << std::endl;
	s1.Print();
}



