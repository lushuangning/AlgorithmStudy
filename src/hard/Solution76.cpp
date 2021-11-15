#include <iostream>
#include <string>
#include "LeetcodePrint.h"

using namespace std;

string minWindow(string s, string t)
{
	vector<int> chars(128, 0);	//ͳ�Ƴ����˼���
	vector<bool> flag(128, false);		//��������˻ᱻ��Ϊtrue

	for (int i = 0; i < t.size(); i++)
	{
		flag[t[i]] = true;
		++chars[t[i]];
	}
	// �ƶ��������ڣ����ϸ���ͳ������
	int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
	for (int r = 0; r < s.size(); r++)
	{
		if (flag[s[r]])
		{
			if (--chars[s[r]] >= 0) {
				++cnt;
			}
			// ��Ŀǰ���������Ѱ���T��ȫ���ַ���
			// ���Խ�l���ƣ��ڲ�Ӱ����������»��������ַ���
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