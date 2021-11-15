#include <iostream>
#include <vector>
#include "SortLogMachine.h"
#include "LeetcodePrint.h"

using namespace std;

void merge(vector<int> &arr, int l, int m, int r);

void process(vector<int> &arr, int l, int r) 
{
	if (l == r)
	{
		return;
	}

	int mid = l + ((r - l) >> 1);
	process(arr, l, mid);
	process(arr, mid+1, r);
	merge(arr, l, mid, r);
}

void merge(vector<int> &arr, int l, int m, int r) 
{
	vector<int> help(r - l + 1);
	int lPtr = l, rPtr = m+1, i = 0;

	while (lPtr <= m && rPtr <= r)
	{
		help[i++] = arr[lPtr] <= arr[rPtr] ? arr[lPtr++] : arr[rPtr++];
	}

	while (lPtr <= m)
	{
		help[i++] = arr[lPtr++];
	}

	while (rPtr <= r)
	{
		help[i++] = arr[rPtr++];
	}

	for (size_t i = 0; i < help.size(); i++)
	{
		arr[l+i] = help[i];
	}
}


int main() 
{
	vector<int> vec = generateRandomVector(10, 0, 100);

	show1DVector(vec);

	cout << "\n";

	process(vec, 0, vec.size() - 1);

	show1DVector(vec);

	return 0;
}