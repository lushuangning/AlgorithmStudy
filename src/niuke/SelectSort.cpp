#include <iostream>
#include <vector>
#include <LeetcodePrint.h>
#include <SortLogMachine.h>

using namespace std;

void selectSort(vector<int>& vec);

// int main()
// {
// 	int n;
// 	cin >> n;

// 	vector<int> vec(n);

// 	for (size_t i = 0; i < n; i++)
// 	{
// 		cin >> vec[i];
// 	}

// 	selectSort(vec);

// 	show1DVector(vec);

// 	return 0;
// }


void selectSort(vector<int> &vec)
{
	int n = vec.size(), minIndex;

	for (int i = 0; i < n-1; ++i)
	{
		minIndex = i;
		for (int j = i+1; j < n; ++j)
		{
			if (vec[minIndex] > vec[j])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)	// 如果这一趟最小值的下标就是第一个，那么不用交换
		{
			// 这样异或交换值为什么会出问题？自己与自己交换肯定是0
			vec[i] = vec[i] ^ vec[minIndex];
			vec[minIndex] = vec[i] ^ vec[minIndex];
			vec[i] = vec[i] ^ vec[minIndex];
		}
	}
}


int main()
{
	int maxSize = 10;
	int maxValue = 100;

	vector<int> vec1 = generateRandomVector(maxSize, 0, maxValue);
	vector<int> vec2 = copyVector(vec1);

	selectSort(vec1);
	sort(vec2.begin(), vec2.end());

	if (isEqual(vec1, vec2))
	{
		cout << "Nice!";
	}

	return 1;
}