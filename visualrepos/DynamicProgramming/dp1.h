#pragma once

// Dynamic Programming 개념

#include <iostream>
#include <map>
#include <string>

// BRUTE FORCE
// TC : O(2^n)
// SC : O(n)

int64_t Fibonacci(int n)
{
	// base case
	if (n <= 2)
	{
		return 1;
	}

	// recursive
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Optimize - 중복계산 제거
// TC : O(n)
// SC : O(n)
int64_t Fibonacci_memo(int n, std::map<int, int64_t>& memo)
{
	if (memo.count(n) == 1)
	{
		return memo[n];
	}
	// base case
	if (n <= 2) { return 1; }

	// recursive
	memo[n] = Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2, memo);
	return memo[n];
}

// m x n 크기의 사각형 영역이 주어졌을 때, 좌상단에서 출발하여 우하단으로 이동하는 경우의 수를 구하세요.
// 단, 이동방향은 오른쪽 혹은 아래쪽으로만 이동 가능
// Brute Force
// TC : O(2 ^ (m+n))
// SC : O(m+n)
int FindWay(int m, int n)
{
	// base case
	if (m == 1 && n == 1) { return 1; }
	if (!m || !n) { return 0; }

	// recursive case
	return FindWay(m - 1, n) + FindWay(m, n - 1);
}

// TC : O(n) / O(m * n)
// SC : O(m+n)
int FindWay(int m, int n, std::map<std::string,int>& memo)
{
	std::string key = std::to_string(m) + "," + std::to_string(n);

	if (memo.count(key) == 1)
	{
		return memo[key];
	}

	std::string rkey = std::to_string(n) + "," + std::to_string(m);

	if (memo.count(rkey) == 1)
	{
		return memo[rkey];
	}

	// base case
	if (m == 1 && n == 1) { return 1; }
	if (!m || !n) { return 0; }

	// recursive case
	memo[key] = FindWay(m - 1, n, memo) + FindWay(m, n - 1, memo);
	return memo[key];
}