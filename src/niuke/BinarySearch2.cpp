#include <iostream>
#include <vector>
#include <LeetcodePrint.h>

using namespace std;

int binarySearch2();

int main()
{
	int a = binarySearch2();
	cout << a;

	return 0;
}


int binarySearch2()
{
	int n, low, high, mid, key, index=-1;

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
		else if (vec[mid] >= key)
		{
			index = mid;
			high = mid - 1;
		}

		mid = (low + high) / 2;
	}



	return index;
}