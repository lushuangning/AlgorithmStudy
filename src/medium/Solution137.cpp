#include <vector>
#include <iostream>

using namespace std;

// 该解法是个通用解，只需改变取余的数，即可解决出现几次的类似题，但不是最优
int singleNumber(vector<int>& nums)
{
	int total = 0, ans = 0;
	for (int i = 0; i < 32; i++)
	{
		for (auto num: nums)
		{
			total += (num >> i) & 1;			// 1的二进制是 00000001，不是11111111，这么做的原因是把答案数该位上的1保留下来
		}

		if (total % 3)	
		{
			ans |= (1 << i);
		}
		total = 0;
	}

	return ans;
}

int main()
{
	vector<int> vec = { 2, 2, 2, 4, 3, 4, 4 };

	cout << singleNumber(vec);

	return 0;
}