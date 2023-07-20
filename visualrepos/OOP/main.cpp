#include <iostream>
#include "infostudent.h"

int main()
{
	const int NAME_LIMIT{50};

	int studentnum{};
	int num{}, score{};
	char name[NAME_LIMIT]{};

	std::cout << "학생 수를 입력해주세요 : " << std::endl;

	std::cin >> studentnum;

	InfoStudent* pInfos = new InfoStudent[studentnum];

	for (int i = 0; i < studentnum; i++)
	{
		std::cout << "------------------------" << std::endl;
		std::cout << "이름 : ";
		std::cin >> name;
		std::cout << "번호 : ";
		std::cin >> num;
		std::cout << "점수 : ";
		std::cin >> score;
		pInfos[i].InputInfo(name, num, score);
	}

	pInfos->Sort(studentnum);

	for (int i = 0; i < studentnum; i++)
	{
		pInfos[i].Print();
		std::cout << std::endl;
	}


	delete[] pInfos;
}



