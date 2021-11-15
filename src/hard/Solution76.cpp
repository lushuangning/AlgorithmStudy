#include <iostream>
#include <string>
#include "LeetcodePrint.h"

using namespace std;

string minWindow(string s, string t)
{
	vector<int> chars(128, 0);	//统计出现了几次
	vector<bool> flag(128, false);		//如果出现了会被置为true

	for (int i = 0; i < t.size(); i++)
	{
		flag[t[i]] = true;
		++chars[t[i]];
	}
	// 移动滑动窗口，不断更改统计数据
	int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
	for (int r = 0; r < s.size(); r++)
	{
		if (flag[s[r]])
		{
			if (--chars[s[r]] >= 0) {
				++cnt;
			}
			// 若目前滑动窗口已包含T中全部字符，
			// 则尝试将l右移，在不影响结果的情况下获得最短子字符串
			while (cnt == t.size())
			{
				if (r - l + 1 < min_size)
				{
					min_l = l;
					min_size = r - l + 1;
				}
				if (flag[s[l]] && ++chars[s[l]] > 0)
				{
					--cnt;
				}
				++l;
			}
		}
	}

	return min_size > s.size() ? "" : s.substr(min_l, min_size);
}

int main()
{
	vector<int> test(5, 0);
	cout << test[0] << endl;
	cout << test[0];
	return 0;
}