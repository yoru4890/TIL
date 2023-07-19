//#include <iostream>
//#include "InfoStudent.h"
//
//int main()
//{
//	int studentNum{};
//
//	std::cout << "학생 수를 입력해주세요 : ";
//
//	std::cin >> studentNum;
//
//	InfoStudent* pInfos = new InfoStudent[studentNum];
//
//
//	delete[] pInfos;
//}
#include <iostream>
#include "String.h"

int main()
{	
	String s1{ "Hello World" };
	s1.Print();
	std::cout << s1.StringLength() << std::endl;

	s1.Strcpy("NO");
	s1.Print();
	std::cout << s1.StringLength() << std::endl;

	String s2{ "YESYESYES" };
	s1.Strcpy(s2);
	s1.Print();
	std::cout << s1.StringLength() << std::endl;

	std::cout << s1.Strcmp("YESYES") << std::endl;
	std::cout << s1.Strcmp("YESYESYES") << std::endl;
	std::cout << s1.Strcmp(s2) << std::endl;

	String s3{ "abcdman" };
	std::cout << s1.Strcmp(s3) << std::endl;
}
