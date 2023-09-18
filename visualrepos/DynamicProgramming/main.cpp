#include <iostream>
#include "dp1.h"
#include "dp2.h"

std::ostream& operator << (std::ostream& os, std::vector<int>* v)
{
	if (v == nullptr)
	{
		std::cout << "nullptr";
	}
	else
	{
		std::cout << "{";
		for (int i = 0; i < v->size(); i++)
		{
			std::cout << (*v)[i];

			if (i < v->size() - 1)
			{
				std::cout << ",";
			}
		}
		std::cout << "}";
	}
	return os;
}

// TC : O(n)
// SC : O(n)
int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

int main()
{
	/*std::map<int, int64_t> memo;
	std::cout << Fibonacci_memo(50, memo) << std::endl;*/

	// std::cout << FindWay(25, 25) << std::endl;
	/*std::map<std::string, int> memo;
	std::cout << FindWay(25, 25, memo) << std::endl;*/

	/*std::vector<int> numbers1{ 2,3,5 };
	int sum1{ 8 };

	std::vector<int> numbers2{ 8,6 };
	int sum2{ 7 };*/

	/*std::cout << std::boolalpha;
	std::cout <<CanAccumulate(numbers1, sum1) << std::endl;

	std::cout << CanAccumulate(numbers2, sum2) << std::endl;

	std::map<int, bool> memo;

	std::cout << CanAccumulate(numbers1, sum1, memo) << std::endl;

	memo.clear();
	std::cout << CanAccumulate(numbers2, sum2, memo) << std::endl;*/

	/*std::map<int, result> memo;
	std::cout << HowAccumulate(numbers1, sum1, memo).get() << std::endl;

	memo.clear();
	std::cout << HowAccumulate(numbers2, sum2, memo).get() << std::endl;

	memo.clear();
	std::cout << OptimizeAccumulate(numbers1, sum1, memo).get() << std::endl;

	memo.clear();
	std::cout << OptimizeAccumulate(numbers2, sum2, memo).get() << std::endl;*/

	std::vector<std::string> strings = { "ab", "abc","cd","def","abcd" };
	auto target = "abcdef";

	/*std::cout << std::boolalpha;
	std::cout << CanGenerate(strings , target) << std::endl;

	std::map<std::string, bool> memo;
	std::cout << CanGenerate(strings, target, memo) << std::endl;*/

	std::cout << HowManyGenerate(strings, target) << std::endl;

	std::map<std::string, int> memo;
	std::cout << HowManyGenerate(strings, target, memo) << std::endl;
}