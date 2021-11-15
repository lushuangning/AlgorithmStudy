#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int>& a, int left, int right);

int findMax(vector<int> &a, int left, int right)
{
	if (left == right)
	{
		return a[left];
	}
	else
	{
		int mid = left + ((right - left) >> 1);	// 中点为什么这么写？
		int maxLeft = findMax(a, left, mid);
		int maxRight = findMax(a, mid+1, right);
		return maxLeft > maxRight ? maxLeft : maxRight;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	cout << "The max is " << findMax(vec, 0, n - 1);
	return 1;
}