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

	std::cout << "�� : " << sum << std::endl;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == min)
		{
			std::cout << "�ּҰ��� ��ġ : " << i << std::endl;
			break;
		}
	}
}