#include <iostream>
#include <vector>
#include "SortLogMachine.h"
#include "LeetcodePrint.h"

using namespace std;

void heapInsert(vector<int> &vec, int index)
{
	// vec[0...index-1] 已经是大根堆了，某个数现在处在 index 位置，往上继续移动
	while ( vec[index] > vec[(index - 1) / 2] ) {

		vec[index] = vec[index] ^ vec[(index - 1) / 2];
		vec[(index - 1) / 2] = vec[index] ^ vec[(index - 1) / 2];
		vec[index] = vec[index] ^ vec[(index - 1) / 2];

		index = ((index - 1) / 2 );
	}
}

// 堆调整
void heapify(vector<int> &vec, int index, int heapSize)
{
	int left = index * 2 + 1;
	while (left < heapSize)		// 左孩子不越界
	{
		// 右孩子也不越界，找到两个孩子中数值较大的那一个的下标
		// 如果没有右孩子，那下标就是左孩子的下标
		int max = left + 1 < heapSize && vec[left + 1] > vec[left] ? left + 1 : left;	

		// 父结点和较大孩子的值进行比较。找到值大的那一个的下标
		max = vec[max] > vec[index] ? max : index;
		if (max == index)
		{
			break;
		}
		vec[index] = vec[index] ^ vec[max];
		vec[max] = vec[index] ^ vec[max];
		vec[index] = vec[index] ^ vec[max];

		index = max;
		left = index * 2 + 1;
	}
}

void heapSort(vector<int> &vec)
{
	int len = vec.size();
	int tmp;

	// O(N logN)
	for (int i = 1; i < len; i++)
	{
		heapInsert(vec, i);
	}

	// 更低的时间复杂度建堆方法，O(N)
	//for (int i = len - 1; i >= 0; i--)
	//{
	//	heapify(vec, i, len);
	//}

	// O(N logN)
	for (int i = len-1; i > 0; i--)
	{
		tmp = vec[len];
		vec[len] = vec[0];
		vec[0] = vec[len];
		heapify(vec, 0, i);
	}
}


int main()
{
	vector<int> vec = generateRandomVector(10, 0, 20);

	show1DVector(vec);

	heapSort(vec);

	show1DVector(vec);

	
	return 0;
}