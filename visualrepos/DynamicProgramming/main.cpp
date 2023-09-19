#include <iostream>
#include "dp1.h"
#include "dp2.h"
#include "dp3.h"

// TC : O(n)
// SC : O(n)
//int f(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//
//	return f(n - 1);
//}

void dp1()
{
	/*std::map<int, int64_t> memo;
	std::cout << Fibonacci_memo(50, memo) << std::endl;*/

	// std::cout << FindWay(25, 25) << std::endl;
	/*std::map<std::string, int> memo;
	std::cout << FindWay(25, 25, memo) << std::endl;*/
}

void dp2()
{
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

	/*std::vector<std::string> strings = { "ab", "abc","cd","def","abcd" };
	auto target = "abcdef";*/

	/*std::cout << std::boolalpha;
	std::cout << CanGenerate(strings , target) << std::endl;

	std::map<std::string, bool> memo;
	std::cout << CanGenerate(strings, target, memo) << std::endl;*/

	/*std::cout << HowManyGenerate(strings, target) << std::endl;

	std::map<std::string, int> memo;
	std::cout << HowManyGenerate(strings, target, memo) << std::endl;*/

	/*std::cout << AllCombination(strings, target) << std::endl;

	std::vector<std::string> strings2 = { "ab", "abc","cd","def","abcd","c","ef"};
	auto target2 = "abcdef";

	std::cout << AllCombination(strings2, target2) << std::endl;*/
}

int main()
{
	using namespace tabulation;
	std::cout << Fibonacci(50) << std::endl;

	std::cout << FindWays(20, 20) << std::endl;
}