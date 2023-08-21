#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>

class Student
{
public:
	int			mNumber;
	std::string mName;
	int			mScore;

public:
	void Print() const
	{
		std::cout << "[" << mNumber << "]" << mName << " : " << mScore << std::endl;
	}
};

void AddStudent(std::vector<Student>& v)
{
	std::cout << "��ȣ �̸� ���� : ";
	Student newStudent{};

	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		/*for (const auto& e : v)
		{
			if (e.mNumber == newStudent.mNumber)
			{
				std::cout << "�ߺ��� ��ȣ�Դϴ�." << std::endl;
				return;
			}
		}
		v.push_back(newStudent);
		*/

		auto itr = std::find_if(v.begin(), v.end(), [&](const auto& e) { return e.mNumber == newStudent.mNumber; });
		if (itr == v.end())
		{
			v.push_back(newStudent);
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(std::vector<Student>& v)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
	int number;
	if (std::cin >> number)
	{
		/*for (auto itr = v.begin(); itr != v.end(); itr++)
		{
			if (itr->mNumber == number)
			{
				v.erase(itr);
				break;
			}
		}*/

		// erase-remove idiom
		v.erase(std::remove_if(v.begin(), v.end(), [&](auto& e) { return e.mNumber == number; }));
	}
	else
	{
		std::cout << "��ȣ�� �Է��� �ּ���" << std::endl;
	}
}

void PrintStudents(const std::vector<Student>& v)
{
	/*for (const auto& e : v)
	{
		e.Print();
	}*/

	std::for_each(v.begin(), v.end(), [](const auto& e) { e.Print(); });
}

void PrintAverage(const std::vector<Student>& v)
{
	int total{};

	/*for (const auto& e : v)
	{
		total += e.mScore;
	}*/

	total = std::accumulate(v.begin(), v.end(), 0, [](int accum, const auto& e)
		{
			return accum += e.mScore;
		});

	std::cout << "���� : " << total << ", ��� : " << total / v.size() << std::endl;
}

void PrintOverAverage(const std::vector<Student>& v)
{
	int total{};

	for (const auto& e : v)
	{
		total += e.mScore;
	}

	int average = total / static_cast<int>(v.size());

	/*for (const auto& e : v)
	{
		if (e.mScore >= average)
		{
			e.Print();
		}
	}*/

	std::for_each(v.begin(), v.end(), [&](const auto& e)
		{
			if (e.mScore >= average)
			{
				e.Print();
			}
			
		});
}

void Ex2()
{
	std::vector<Student> students_v{
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 40},
		{4, "Choi", 30}
	};

	

	// { ��ȣ, �̸�, ���� }
	// 1. �߰�
	// 2. ����
	// 3. ���
	// 4. ���, ����
	// 5. ��� �̻��� �л� ���
	// 6. ����

	bool isQuit{ false };
	while (!isQuit)
	{
		std::cout << "1. �л� �߰�" << std::endl;
		std::cout << "2. �л� ����(��ȣ)" << std::endl;
		std::cout << "3. ��ü �л� ���" << std::endl;
		std::cout << "4. ���� �� ���" << std::endl;
		std::cout << "5. ��� �̻��� ���" << std::endl;
		std::cout << "6. ����" << std::endl;
		std::cout << "> ";

		int command{};
		std::cin >> command;

		switch (command)
		{
			case 1:
				AddStudent(students_v);
				break;
			case 2:
				RemoveStudent(students_v);
				break;
			case 3:
				PrintStudents(students_v);
				break;
			case 4:
				PrintAverage(students_v);
				break;
			case 5:
				PrintOverAverage(students_v);
				break;
			case 6:
				isQuit = true;
				break;
			default:
				std::cerr << "�߸��� ����Դϴ�." << std::endl;
				break;
		}
	}
}

std::ostream& operator << (std::ostream& os, const Student& s)
{
	os << "[" << s.mNumber << "]" << s.mName << " : " << s.mScore << std::endl;

	return os;
}

void AddStudent(std::map<int, Student>& m)
{
	std::cout << "��ȣ �̸� ���� : ";
	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		auto result = m.insert({ newStudent.mNumber, newStudent });
		if (!result.second)
		{
			std::cout << "�ߺ��� �л� ��ȣ�Դϴ�." << std::endl;
			return;
		}

		// std::pair<std::map<int, Student>::iterator , bool >
	}
	else
	{
		std::cerr << "�߸��� �Է��Դϴ�.";
	}
}

			
void RemoveStudent(std::map<int, Student>& m)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
	int number;
	if (std::cin >> number)
	{
		m.erase(number);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�.";
	}
}
				
			
void PrintStudents(const std::map<int, Student>& m)
{
	for (const auto& e : m)
	{
		std::cout << e.second << std::endl;
	}
}
				
			
void PrintAverage(const std::map<int, Student>& m)
{
	int total{};

	total = std::accumulate(m.begin(), m.end(), 0, [](int accum, const auto& pair)
		{
			return accum += pair.second.mScore;
		});

	std::cout << "���� : " << total << ", ��� : " << total / m.size() << std::endl;
}
			
void PrintOverAverage(const std::map<int, Student>& m)
{
	int average{};

	average = std::accumulate(m.begin(), m.end(), 0, [](int accum, const auto& pair)
		{
			return accum += pair.second.mScore;
		});

	average /= m.size();

	std::for_each(m.begin(), m.end(), [&](const auto& pair)
		{
			if (pair.second.mScore >= average)
			{
				std::cout << pair.second << std::endl;
			}
		});
}

void Ex2_Map()
{
	std::map<int, Student> students
	{
		{1, {1, "Kim", 80}},
		{2, {2, "Lee", 20}},
		{3, {3, "Park", 40}},
		{4, {4, "Choi", 30}}
	};

	// { ��ȣ, �̸�, ���� }
	// 1. �߰�
	// 2. ����
	// 3. ���
	// 4. ���, ����
	// 5. ��� �̻��� �л� ���
	// 6. ����

	bool isQuit{ false };
	while (!isQuit)
	{
		std::cout << "1. �л� �߰�" << std::endl;
		std::cout << "2. �л� ����(��ȣ)" << std::endl;
		std::cout << "3. ��ü �л� ���" << std::endl;
		std::cout << "4. ���� �� ���" << std::endl;
		std::cout << "5. ��� �̻��� ���" << std::endl;
		std::cout << "6. ����" << std::endl;
		std::cout << "> ";

		int command{};
		std::cin >> command;

		switch (command)
		{
			case 1:
				AddStudent(students);
				break;
			case 2:
				RemoveStudent(students);
				break;
			case 3:
				PrintStudents(students);
				break;
			case 4:
				PrintAverage(students);
				break;
			case 5:
				PrintOverAverage(students);
				break;
			case 6:
				isQuit = true;
				break;
			default:
				std::cerr << "�߸��� ����Դϴ�." << std::endl;
				break;
		}
	}
}