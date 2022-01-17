// —’…´∑÷¿‡

#include <iostream>
#include <vector>
#include <algorithm>
#include <LeetcodePrint.h>

using namespace std;

void sortColors(vector<int> &nums) {
	int length = nums.size();
	int L = -1, R = length;
	int i = 0;

	while(i < R) {
		if (nums[i] < 1) {
			swap(nums[++L], nums[i++]);
		}
		else if (nums[i] == 1) {
			i++;
		}
		else {
			swap(nums[--R], nums[i]);
		}
	}
}

int main() {
	vector<int> nums = { 2, 2, 1, 0, 2, 1, 0, 0 , 1, 2};
	sortColors(nums);
	show1DVector(nums);
	return 0;
}