#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums;
	int num{}, sum{}, min{};

	while (std::cin >> num)
	{
		nums.push_back(num);
	}

	min = num;

	for (int n : nums)
	{
		sum += n;
	}

	for (int n : nums)
	{
		if (n < min)
		{
			min = n;
		}
	}

	std::cout << "합 : " << sum << std::endl;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == min)
		{
			std::cout << "최소값의 위치 : " << i << std::endl;
			break;
		}
	}
}