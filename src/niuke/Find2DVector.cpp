#include <iostream>
#include <vector>
#include "LeetcodePrint.h"

using namespace std;

bool Find(int target, vector<vector<int>>& array);

bool Find(int target, vector<vector<int>>& array)
{
	int m, n, s, e;

	m = array.size();
	n = array[0].size();

	cout << "m size is " << m << "\n";

	s = 0, e = m - 1;

	while (s < n && e >= 0) {
		if (array[e][s] == target)
		{
			return true;
		}
		else if (array[e][s] < target)
		{
			s++;
		}
		else {
			e--;
		}
	}
	return false;
}

int main()
{
	int m, n, target;
	cin >> m;
	cin >> n;

	vector<int> w(n);
	vector<vector<int>> arr(m, w);

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "Please input a target: ";

	cin >> target;
	if (Find(target, arr)) 
	{
		cout << "The number you input is in the matrix";
	}
	else
	{
		cout << "Sorry, number " << target << " doesn't exists";
	}
	
	return 0;
}