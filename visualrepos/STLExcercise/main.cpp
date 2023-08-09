#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
	int mNumber;
	int mScore;
	std::string mName;
};

std::ostream& operator << (std::ostream& os, std::vector<Student> v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		std::cout << it->mNumber << ", " << it->mScore << ", " << it->mName << std::endl;
	}

	return os;
}

bool CompareDescending(const Student* x, const Student& y)
{
	return x->mScore > y.mScore;
}

int main()
{
	std::vector<Student> students{
		{1, 100, "Doggy"},
		{ 2, 50, "kitty" },
		{ 3, 90, "Piggy" },
		{ 4, 20 , "Bunny" }
	};

	/*struct CompareAscending
	{
		bool operator() (Student x, Student y)
		{
			return x.mScore < y.mScore;
		}
	};

	CompareAscending c;

	std::sort(students.begin(), students.end(), c);*/
	
	//std::sort(students.begin(), students.end(), CompareDescending);

	std::sort(students.begin(), students.end(), [](Student x, Student y)
		{
			return x.mScore < y.mScore;
		});					

	std::cout << students << std::endl;

	return 0;
}