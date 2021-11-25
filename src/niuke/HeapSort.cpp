#include <iostream>
#include <vector>
#include "SortLogMachine.h"
#include "LeetcodePrint.h"

using namespace std;

void heapInsert(vector<int> &vec, int index)
{
	// vec[0...index-1] �Ѿ��Ǵ�����ˣ�ĳ�������ڴ��� index λ�ã����ϼ����ƶ�
	while ( vec[index] > vec[(index - 1) / 2] ) {

		vec[index] = vec[index] ^ vec[(index - 1) / 2];
		vec[(index - 1) / 2] = vec[index] ^ vec[(index - 1) / 2];
		vec[index] = vec[index] ^ vec[(index - 1) / 2];

		index = ((index - 1) / 2 );
	}
}

// �ѵ���
void heapify(vector<int> &vec, int index, int heapSize)
{
	int left = index * 2 + 1;
	while (left < heapSize)		// ���Ӳ�Խ��
	{
		// �Һ���Ҳ��Խ�磬�ҵ�������������ֵ�ϴ����һ�����±�
		// ���û���Һ��ӣ����±�������ӵ��±�
		int max = left + 1 < heapSize && vec[left + 1] > vec[left] ? left + 1 : left;	

		// �����ͽϴ��ӵ�ֵ���бȽϡ��ҵ�ֵ�����һ�����±�
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

	// ���͵�ʱ�临�ӶȽ��ѷ�����O(N)
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