#include "SortLogMachine.h"


// maxSize �����ģ, minValue ����Ԫ�ص���Сֵ��maxValue ����Ԫ�ص����ֵ
vector<int> generateRandomVector(int maxSize, int minValue, int maxValue)
{
	assert(minValue < maxValue);

	int size = rand() % (maxSize + 1); // ������[0, maxSize] ������

	vector<int> vec(size);

	for (int i = 0; i < size; i++)
	{
		vec[i] = (rand() % (maxValue - minValue + 1)) + minValue;	// ������ [minValue-maxValue] ������
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

