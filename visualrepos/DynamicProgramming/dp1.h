#pragma once
#include <iostream>
#include <map>

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

// Optimize - �ߺ���� ����
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

// m x n ũ���� �簢�� ������ �־����� ��, �»�ܿ��� ����Ͽ� ���ϴ����� �̵��ϴ� ����� ���� ���ϼ���.
// ��, �̵������� ������ Ȥ�� �Ʒ������θ� �̵� ����
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