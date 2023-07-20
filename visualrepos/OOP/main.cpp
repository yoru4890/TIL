#include <iostream>
#include "infostudent.h"

int main()
{
	const int NAME_LIMIT{50};

	int studentnum{};
	int num{}, score{};
	char name[NAME_LIMIT]{};

	std::cout << "�л� ���� �Է����ּ��� : " << std::endl;

	std::cin >> studentnum;

	InfoStudent* pInfos = new InfoStudent[studentnum];

	for (int i = 0; i < studentnum; i++)
	{
		std::cout << "------------------------" << std::endl;
		std::cout << "�̸� : ";
		std::cin >> name;
		std::cout << "��ȣ : ";
		std::cin >> num;
		std::cout << "���� : ";
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



