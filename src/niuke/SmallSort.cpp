#include <iostream>
#include <vector>
#include "SortLogMachine.h"
#include "LeetcodePrint.h"

using namespace std;

int merge(vector<int> &vec, int l, int m, int r)
{
	int p1 = l, p2 = m + 1, i = 0, res = 0;

	vector<int> help(r - l + 1);
	while (p1 <= m && p2 <= r)
	{
		res += vec[p1] < vec[p2] ? (r - p2 + 1) * vec[p1]: 0;	// 求小和的过程
		help[i++] = vec[p1] < vec[p2] ? vec[p1++] : vec[p2++];	// merge 的过程。注意这里与归并排序有区别，这里是小于
	}

	while (p1 <= m)
	{
		help[i++] = vec[p1++];
	}

	while (p2 <= r)
	{
		help[i++] = vec[p2++];
	}

	for (size_t i = 0; i < help.size(); i++)
	{
		vec[l + i] = help[i];
	}

	return res;
}

int process(vector<int>& vec, int l, int r)
{
	if (l == r)
	{
		return 0;
	}
	int m = l + ((r - l) >> 1);

	return process(vec, l, m) + process(vec, m + 1, r) + merge(vec, l, m, r);
}

int main()
{
	vector<int> vec = generateRandomVector(10, 0, 100);
	
	show1DVector(vec);
	
	

	cout << process(vec, 0, vec.size() - 1);



	return 0;
}