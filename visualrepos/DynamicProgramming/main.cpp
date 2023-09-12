#include <iostream>
#include "dp1.h"

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

	std::cout << FindWay(25, 25) << std::endl;
}