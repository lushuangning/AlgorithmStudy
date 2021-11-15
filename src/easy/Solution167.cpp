#include <vector>
#include <iostream>
#include "LeetcodePrint.h"

using namespace std;

// 使用迭代器 iterator
vector<int> twoSum(vector<int>& numbers, int target) 
{
	vector<int>::iterator head, tail;
	head = numbers.begin();
	tail = numbers.end() - 1;
	int a, b;
	while (true)
	{
		if (*head + *tail < target) {
			head = head + 1;
		}
		else if (*head + *tail > target)
		{
			tail = tail - 1;
		}
		else
		{
			a = head - numbers.begin() + 1;	//迭代器转换成 index
			b = tail - numbers.begin() + 1;
			break;
		}
	}

	return vector<int>{a, b};
}

int main()
{
	vector<int> num = { 1, 3, 5, 7, 9 };
	vector<int> test = twoSum(num, 12);
	show1DVector(test);
	return 0;
}