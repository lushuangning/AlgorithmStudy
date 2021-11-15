//
// Created by 路双宁 on 2021/3/9.
//

#include <iostream>
#include <vector>
using namespace std;
//最简单方法
//vector<int> Solution1470::shuffle(vector<int>& nums, int n) {
//    vector<int> a,b;
//    for (int i = 0; i < n; ++i) {
//        a.push_back(nums[i]);
//    }
//    for (int i = n; i < 2*n; ++i) {
//        b.push_back(nums[i]);
//    }
//    nums.clear();
//    for (int i = 0;i < n; ++i){
//        nums.push_back(a[i]);
//        nums.push_back(b[i]);
//    }
//    return nums;
//}

// 空间复杂度O(1)解法
vector<int> shuffle(vector<int>& nums, int n) 
{
    for (int i = 0; i < 2*n; ++i) 
    {
        int j = (i<n) ? 2*i : 2*(i-n) + 1;
        nums[j] |= (nums[i] & 1023) << 10;
    }
    for(int &e : nums){ e >> 10; }
    return nums;
}