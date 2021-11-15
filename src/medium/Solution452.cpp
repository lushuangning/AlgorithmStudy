#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "LeetcodePrint.h"

using namespace std;

int findMinArrowShots(vector<vector<int>>& points);

int findMinArrowShots(vector<vector<int>>& points)
{
	if (points.empty())
	{
		return 0;
	}
	int n = points.size();
	int total = 1, prevnum = points[0][1];
	sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
		return a[1] < b[1];
	});

	//for (int i = 1;i < n;++i)
	//{
	//	if (points[i][0] > prevnum)
	//	{
	//		total++;
	//		prevnum = points[i][1];
	//	}
	//}
	for (const vector<int> &ballon:points)
	{
		if (ballon[0] > prevnum)
		{
			prevnum = ballon[1];
			++total;
		}
	}

	return total;
}

int main()
{
	vector<vector<int>> a{ {10,16},{2,8},{1,6},{7,12} };
	int out = findMinArrowShots(a);
	show2DVector(a);
	cout << endl << "Output: " << out << endl;

	return 0;
}