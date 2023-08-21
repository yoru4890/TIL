#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//#include "Ex1.h"
#include "Ex2.h"

void PrintVector2D()
{
	int m{}, n{};

	std::cin >> m >> n;

	std::vector<std::vector<int>> v(m, std::vector<int>(n, -1));

	std::cout << "{" << std::endl;

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "{";

		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j];
			if (j < v[i].size()-1)
			{
				std::cout << ",";
			}
		}

		std::cout << "}";
		if (i < v.size() - 1)
		{
			std::cout << "," << std::endl;
		}
	}

	std::cout << std::endl << "}" << std::endl;
}

bool IsSameImage(std::string s, std::string t)
{
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	return s == t;
}

char MaxLetter(const std::string& s)
{
	std::map<char, int> table;
	char maxChar{};
	int max{ -1 };

	for (const auto& e : s)
	{
		table[e]++;

		if (table[e] > max)
		{
			maxChar = e;
			max = table[e];
		}
	}

	return maxChar;
}

int main()
{
	//Ex1();
	//Ex2();
	//Ex2_Map();

	//PrintVector2D();

	/*std::string s = "acdfc1";
	std::string t = "dca1cf";
	std::cout << std::boolalpha << IsSameImage(s, t) << std::endl;*/

	std::cout << MaxLetter("hhhhhhheeeellleeehhooood") << std::endl;

}