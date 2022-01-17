// 合并两个有序数组

#include <vector>
#include <iostream>
#include <algorithm>
#include "LeetcodePrint.h"

using namespace std;

// 借助STL排序函数，但时间复杂度高于 m + n
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
//{
//
//	for (int i = 0; i < nums2.size(); i++)
//	{
//		nums1[m++] = nums2[i];
//	}
//	sort(nums1.begin(), nums1.end());
//}


// O(m + n)复杂度的算法
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int pos = m-- + n-- - 1;
	while (m >= 0 && n >= 0)
	{
		nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}
	while(n >= 0)
	{
		nums1[pos--] = nums2[n--];
	}
}

int main()
{
	vector<int> n1 = { 1,2,3,0,0,0 };
	vector<int> n2 = { 2,5,6 };
	merge(n1, 3, n2, 3);
	show1DVector(n1);
	return 0;
}