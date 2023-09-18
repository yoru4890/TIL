#pragma once
#include <vector>
#include <memory>

// DynamicProgramming - Memoization

// Brute Force
// m : sum, n : numbersdml ũ��
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
// m : sum, n : numbersdml ũ��
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
//		O( m ) - �Է� ����� ���⵵���� ���� 
using result = std::shared_ptr<std::vector<int>>;
result HowAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum)) { return memo[sum]; }

	// base case
	if (!sum) { return std::make_shared<std::vector<int>>(); }  // {}
	if (sum < 0) { return nullptr; }

	// recursive
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
// �ּ��� ũ��
// TC : O (m * n)
//		std::copy �ð� ��� O(m^2 * n)
// SC : O (m ^ 2)
result OptimizeAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}
	// base case
	if (!sum) { return std::make_shared<std::vector<int>>(); }
	else if (sum < 0) { return nullptr; }

	// recursive
	std::shared_ptr<std::vector<int>> optimized = nullptr;
	for (const auto& e : numbers)
	{
		auto r = OptimizeAccumulate(numbers, sum - e, memo);

		if (r)
		{
			std::shared_ptr<std::vector<int>> v = std::make_shared<std::vector<int>>();
			v->resize(r->size());
			std::copy(r->begin(), r->end(), v->begin());

			v->push_back(e);

			if (!optimized || v->size() < optimized->size()) { optimized = v; }
		
		}
	}

	memo[sum] = optimized;
	return memo[sum];
}

//////////////////////////////////////////////////////////////////////////////////////
// 
// Decision Problem Brute Force
// m : target, n : strings�� ũ��
// TC : O( n ^ m * m )
// SC : O (m ^ 2)
bool CanGenerate(const std::vector<std::string>& strings, std::string target)
{
	// base case
	if (target == "") { return true; }

	// recursive
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			if (CanGenerate(strings, target.substr(e.size())))
			{
				return true;
			}
		}
	}

	return false;
}

// Decision Problem Memoization
// TC : O (m^2 * n)
// SC : O (m^2)

bool CanGenerate(const std::vector<std::string>& strings, std::string target, std::map<std::string, bool>& memo)
{
	if (memo.count(target) == 1) { return memo[target]; }
	// base case
	if (target == "") { return true; }

	// recursive
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			if (CanGenerate(strings, target.substr(e.size())))
			{
				memo[target] = true;
				return memo[target];
			}
		}
	}

	memo[target] = false;
	return memo[target];
}

// Combination - Brute Force
// TC : O(n^m * m)
// SC : O(m^2)
int HowManyGenerate(const std::vector<std::string>& strings, std::string target)
{
	// base case
	if (target == "") { return 1; }

	// recursive
	int count{};
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			count += HowManyGenerate(strings, target.substr(e.size()));
		}
	}
	return count;
}

// Combination - Memoization
// TC : O( n * m^2 )
// SC : O( m^2 )
int HowManyGenerate(const std::vector<std::string>& strings, std::string target, std::map<std::string, int>& memo)
{
	if (memo.count(target) == 1) { return memo[target]; }

	// base case
	if (target == "") { return 1; }

	// recursive
	int count{};
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			count += HowManyGenerate(strings, target.substr(e.size()), memo);
		}
	}

	memo[target] = count;
	return memo[target];
}
