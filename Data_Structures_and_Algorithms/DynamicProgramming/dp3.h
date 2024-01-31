#pragma once
#include <iostream>
#include <vector>
#include <list>

namespace tabulation
{
	// tabluation
	// TC : O(n)
	// SC : O(n)
	int64_t Fibonacci(const int n)
	{
		std::vector<int64_t> table(n + 1, 0);

		// base case
		table[0] = 0;
		table[1] = 1;

		// traverse
		for (int i = 0; i <= n; i++)
		{
			if (i + 1 <= n)
			{
				table[i + 1] += table[i];
			}
			if (i + 2 <= n)
			{
				table[i + 2] += table[i];
			}
		}

		return table[n];
	}

	// TC : O(m * n)
	// SC : O(m * n)
	int FindWays(int m, int n)
	{
		std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

		// base case
		table[1][1] = 1;

		// traverse
		for (int row = 0; row <= m; ++row)
		{
			for (int col = 0; col <= n; ++col)
			{
				if (row + 1 <= m)
				{
					table[row + 1][col] += table[row][col];
				}
				if (col + 1 <= n)
				{
					table[row][col + 1] += table[row][col];
				}

			}
		}

		return table[m][n];
	}

	// m : sum, n : numbers Å©±â
	// TC : O(m * n)
	// SC : O(m)

	bool CanAccumulate(const std::vector<int>& numbers, int sum)
	{
		std::vector<bool> table(sum + 1, false);

		// base case
		table[0] = true;

		// iterate
		for (int i = 0; i <= sum; i++)
		{
			if (table[i] == false)
			{
				continue;
			}
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = true;
				}
			}
		}

		return table[sum];
	}

	// TC : O(m*n*m) = O(m^2*n)
	// SC : O(m * m) = O(m^2)
	std::shared_ptr<std::vector<int>> HowAccumulate(const std::vector<int>& numbers, int sum)
	{
		std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);
		// base case
		table[0] = std::make_shared < std::vector<int>>();

		// iteration
		for (int i = 0; i <= sum; ++i)
		{
			if (table[i] == nullptr)
			{
				continue;
			}

			for (const auto& e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}

		return table[sum];
	}

	// TC : O (m^2*n)
	// SC : O (m^2)
	std::shared_ptr<std::vector<int>> OptimizeAccumulate(const std::vector<int>& numbers, int sum)
	{
		std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);

		// base case
		table[0] = std::make_shared<std::vector<int>>();

		// iteration
		for (int i = 0; i <= sum; i++)
		{
			if (table[i] == nullptr)
			{
				continue;
			}

			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					if (table[i + e] == nullptr || table[i + e]->size() - 1 > table[i]->size())
					{
						table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}

		return table[sum];
	}

	// TC : O(m^2*n)
	// SC : O(m)

	bool CanGenerate(const std::vector<std::string>& strings, const std::string& target)
	{
		std::vector<bool> table(target.size() + 1, false);

		// base case
		table[0] = true;

		for (int i = 0; i <= target.size(); ++i)
		{
			if (table[i] == false)
			{
				continue;
			}

			for (auto e : strings)
			{
				int size = static_cast<int>(e.size());
				if (target.substr(i, size) == e)
				{
					if (i + size <= target.size())
					{
						table[i + size] = true;
					}
				}
			}
		}
		return table[target.size()];
	}

	// TC : O(m * n * m) == O(m^2*n)
	// SC : O(m+m) = O(m)

	int HowManyGenerate(const std::vector<std::string>& strings, const std::string target)
	{
		std::vector<int> table(target.size() + 1, 0);

		// base case
		table[0] = 1;

		// iteration
		for (int i = 0; i <= target.size(); i++)
		{
			if (table[i] == 0)
			{
				continue;
			}

			for (auto e : strings)
			{
				if (target.substr(i, e.size()) == e)
				{
					if (i + e.size() <= target.size())
					{
						table[i + e.size()] += table[i];
					}
				}
			}
		}
		return table[target.size()];
	}

	// TC : O(m^2*n)
	// SC : O(m*n)

	std::list<std::list<std::string>> AllGenerate(const std::vector<std::string>& strings, std::string target)
	{
		std::vector<std::list<std::list<std::string>>> table(target.size()+1);

		// base case
		table[0] = { {} }; //std::list<std::list<std::string>>(1, std::list<std::string>());
		
		// iterate
		for (int i = 0; i <= target.size(); i++)
		{
			for (auto e : strings)
			{
				if (target.substr(i, e.size()) == e)
				{
					if (i + e.size() <= target.size())
					{
						for (auto e2 : table[i])
						{
							e2.push_back(e);
							table[i + e.size()].push_back(e2);
						}
					}
				}
			}
		}
		return table[target.size()];
	}
}



