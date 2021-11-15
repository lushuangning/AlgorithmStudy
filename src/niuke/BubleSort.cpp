#include <iostream>
#include <vector>
#include <LeetcodePrint.h>

using namespace std;

void bubleSort();

int main()
{
	bubleSort();

	return 0;
}


void bubleSort()
{
	int n;
	cin >> n;
	
	vector<int> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	for (int i = n-1; i > 0; i--)
	{
		for (int  j = 0; j < i; j++)
		{
			if (vec[j] > vec[j+1])
			{
				vec[j] = vec[j] ^ vec[j + 1];
				vec[j + 1] = vec[j] ^ vec[j + 1];
				vec[j] = vec[j] ^ vec[j + 1];
			}
		}
	}

	show1DVector(vec);
}