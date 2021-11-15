#include "SortLogMachine.h"


// maxSize 数组规模, minValue 数组元素的最小值，maxValue 数组元素的最大值
vector<int> generateRandomVector(int maxSize, int minValue, int maxValue)
{
	assert(minValue < maxValue);

	int size = rand() % (maxSize + 1); // 产生从[0, maxSize] 的整数

	vector<int> vec(size);

	for (int i = 0; i < size; i++)
	{
		vec[i] = (rand() % (maxValue - minValue + 1)) + minValue;	// 产生从 [minValue-maxValue] 的整数
	}

	return vec;
}

vector<int> copyVector(vector<int>& vec)
{
	vector<int> vec2(vec);

	return vec2;
}

bool isEqual(vector<int>& vec1, vector<int>& vec2)
{

	return (vec1 == vec2);
}

