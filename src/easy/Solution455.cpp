// 分发饼干

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);

int findContentChildren(vector<int>& g, vector<int>& s)
{
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	int child = 0, cookie = 0;
	while (child < g.size() && cookie < s.size())
	{
		if (g[child] <= s[cookie]) { child++;}
		cookie++;
	}

	return child;
}

int main()
{
	vector<int> g = {1, 2};
	vector<int> s = { 1, 2, 3 };

	cout << "有" << findContentChildren(g, s) << "个孩子可以吃饱" << endl;

	return 0;
}