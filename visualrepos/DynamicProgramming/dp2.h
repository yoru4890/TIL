#pragma once
#include <vector>
#include <memory>

// DynamicProgramming - Memoization

// Brute Force
// m : sum, n : numbersdml 크기
// TC : O( n ^ m )
// SC : O( m )
bool CanAccumulate(const std::vector<int>& numbers, int sum)
{
	// base case
	if (!sum) { return true; }
	if (sum < 0) { return false; }

	// recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e)) { return true; }
	}

	return false;
}

// Memoization
// m : sum, n : numbersdml 크기
// TC : O( m * n )
// SC : O( m )
bool CanAccumulate(const std::vector<int>& numbers, int sum, std::map<int, bool>& memo)
{
	if (memo.count(sum)) { return memo[sum]; }
	// base case
	if (!sum) { return true; }
	if (sum < 0) { return false; }

	// recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e, memo))
		{
			memo[sum] = true;
			return true;
		}
	}

	memo[sum] = false;
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////

// Memoization
// TC : O (m * n)
// SC : O (m ^ 2), 
//		O( m ) - 입력 출력은 복잡도에서 제외 
using result = std::shared_ptr<std::vector<int>>;
result HowAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum)) { return memo[sum]; }

	// base case
	if (!sum) { return std::make_shared<std::vector<int>>(); }  // {}
	if (sum < 0) { return nullptr; }

	// recursive case
	for (const auto e : numbers)
	{
		auto r = HowAccumulate(numbers, sum - e, memo);
		if (r) 
		{
			r->push_back(e); 
			memo[sum] = r;
			return memo[sum];
		}
	}

	memo[sum] = nullptr;
	return memo[sum];
}

///////////////////////////////////////////////////////////////////////////////////
// 최소의 크기
