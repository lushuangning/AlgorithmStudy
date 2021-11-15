//
// Created by 路双宁 on 2021/3/13.
//

#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum+=nums[i];
        nums[i]=sum;
    }

    return nums;
}

int main()
{

    return 1;
}