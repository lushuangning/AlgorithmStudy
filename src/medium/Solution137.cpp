#include <vector>
#include <iostream>

using namespace std;

// �ýⷨ�Ǹ�ͨ�ý⣬ֻ��ı�ȡ����������ɽ�����ּ��ε������⣬����������
int singleNumber(vector<int>& nums)
{
	int total = 0, ans = 0;
	for (int i = 0; i < 32; i++)
	{
		for (auto num: nums)
		{
			total += (num >> i) & 1;			// 1�Ķ������� 00000001������11111111����ô����ԭ���ǰѴ�����λ�ϵ�1��������
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