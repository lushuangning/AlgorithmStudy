//
// Created by 路双宁 on 2021/3/19.
//

#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int max=0;

    for (int i = 0; i < prices.size(); ++i) 
    {
        for (int j = i+1; j < prices.size(); ++j) 
        {
            int tmp = prices[j] - prices[i];
            if (tmp > max){
                max = tmp;
            }
        }
    }

    return max;
}

int main()
{
    
    return 1;
}
