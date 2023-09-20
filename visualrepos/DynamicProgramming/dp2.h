#pragma once
#include <vector>
#include <memory>
#include <list>

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

using  string2d = std::list<std::list<std::string>>;
std::ostream& operator << (std::ostream& os, const string2d& v)
{
	std::cout << "{" << std::endl;
	for (int i{}; auto e1 : v)
	{
		std::cout << "    {";
		for (int j{}; auto e2 : e1)
		{
			std::cout << e2;
			if (j < e1.size() - 1)
			{
				std::cout << ",";
			}
			j++;
		}
		std::cout << "}";
		if (i < v.size() - 1)
		{
			std::cout << ",";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "}" << std::endl;

	return os;
}

namespace memoization
{

	

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
	// 최소의 크기
	// TC : O (m * n)
	//		std::copy 시간 고려 O(m^2 * n)
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
	// m : target, n : strings의 크기
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

	

	// TC : O(n^m * m)
	// SC : O(m^2)
	string2d AllCombination(const std::vector<std::string>& strings, std::string target)
	{
		// base case
		if (target == "")
		{
			return string2d{ {} };
		}
		// recursive
		string2d v;
		for (auto word : strings)
		{
			if (target.find(word) == 0)
			{
				auto r = AllCombination(strings, target.substr(word.size()));
				for (auto s : r)
				{
					s.push_front(word);
					v.push_front(s);
				}
			}
		}

		return v;
	}
}