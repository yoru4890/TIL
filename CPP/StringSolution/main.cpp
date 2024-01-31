#include <iostream>
#include "String.h"

int main()
{
	std::cout << "------1------" << std::endl;

	String empty;
	std::cout << empty << std::endl;
	std::cout << empty.Length() << std::endl;

	std::cout << "------2------" << std::endl;

	String sized(10);
	std::cout << sized << std::endl;
	std::cout << sized.Length() << std::endl;

	std::cout << "------3------" << std::endl;

	String s1("hello");
	std::cout << s1 << std::endl;
	std::cout << s1.Length() << std::endl;

	std::cout << "------4------" << std::endl;

	String s2(s1);
	std::cout << s2 << std::endl;
	std::cout << s2.Length() << std::endl;

	std::cout << "------5------" << std::endl;

	String s3 = s1 + s2;
	std::cout << s3 << std::endl;
	std::cout << s3.Length() << std::endl;

	String s4;
	s4 += s3;
	std::cout << s4 << std::endl;
	std::cout << s4.Length() << std::endl;

	std::cout << "------6------" << std::endl;

	std::cout << s4[0] << s4[1] << std::endl;
	s4[0] = 'H';
	std::cout << s4 << std::endl;

	std::cout << "------7------" << std::endl;

	empty = s4;
	std::cout << empty << std::endl;
	std::cout << empty.Length() << std::endl;

	s4 = s4;
	std::cout << s4 << std::endl;
	std::cout << s4.Length() << std::endl;

}