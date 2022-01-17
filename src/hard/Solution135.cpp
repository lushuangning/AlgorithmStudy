// �ַ��ǹ�

#include <vector>
#include <iostream>
#include <algorithm>
#include<numeric>

using namespace std;
int candy(vector<int>& ratings);

int candy(vector<int>& ratings) {
	int size = ratings.size();
	vector<int> num(size, 1);		//������������Ԫ�ص�ֵ��Ϊ1
	if (size < 2) { return size; }
	for (int i = 1;i < size;i++)
	{
		if (ratings[i] > ratings[i-1])
		{
			num[i] = num[i-1] + 1;
		}
	}

	for (int i = size - 1;i > 0;i--)
	{
		if (ratings[i-1] > ratings[i] && num[i-1] <= num[i])
		{
			num[i-1] = num[i] + 1;
		}
	}

	return accumulate(num.begin(), num.end(), 0);		//�������������ۼӵĳ�ֵ
}

int main()
{
	vector<int> a = { 1,0,2 };
	cout << "Output: " << candy(a) << endl;

	return 0;
}