#include <iostream>
#include <vector>
#include <LeetcodePrint.h>

using namespace std;

int binarySearch();

int main()
{
	int a = binarySearch();
	cout << a;

	return 0;
}


int binarySearch()
{
	int n, low, high, mid, key;
	cin >> n;

	cin >> key;

	vector<int> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	low = 0, high = n - 1, mid = (low + high) / 2;

	while ((mid >= low) && (mid <= high))
	{
		if (vec[mid] < key)
		{
			low = mid + 1;
		}
		else if (vec[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}

		mid = (low + high) / 2;
	}

	return -1;
}