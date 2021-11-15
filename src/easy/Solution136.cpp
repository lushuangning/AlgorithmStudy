#include <vector>
#include <iostream>

using namespace std;

int singleNumber(vector<int>& nums)
{
	int ero = 0;
	for (auto a : nums)
	{
		ero ^= a;
	}

	return ero;
}

int main()
{
	vector<int> vec = {2, 2, 4, 4, 3, 4, 4};

	cout << singleNumber(vec);

	return 0;
}