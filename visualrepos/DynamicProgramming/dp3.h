#pragma once
#include <iostream>
#include <vector>

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

}



