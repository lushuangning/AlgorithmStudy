//
// Created by 路双宁 on 2021/3/18.
//

#include <vector>

using namespace std;

int climbStairs(int n);

/*
 * 递归，本质是斐波那契数列，时间复杂度O(2^n)，空间复杂度O(n)。可以用记忆递归的方法将时间复杂度降低到O(n)
 */

//int climbStairs(int n){
//    if (n <= 0)
//        return -1;
//    if (n <= 2)
//        return n;
//
//    return climbStairs(n-1) + climbStairs(n-2);
//}

/*
 * 记忆化递归
 */

//int climbStairs(int n){
//
//    vector<int> vec(n+1, -1);
//
//    if (n <= 2){
//        return n;
//    }
//
//    if (vec[n-1] == -1){
//        vec[n-1] = climbStairs(n-1);
//    }
//
//    if (vec[n-2] == -1){
//        vec[n-2] = climbStairs(n-2);
//    }
//
//    vec[n] = vec[n-1] + vec[n-2];
//
//    return vec[n];
//}


/*
 * 动态规划，利用滚动数组将空间复杂度降低到O(1)
 */

int climbStairs(int n)
{
    int temp=0, i1 = 1, i2 = 2;
    if (n <= 2){
        return n;
    }

    for (int i = 3; i <= n; ++i) 
    {
        temp = i1 + i2;
        i1 = i2;
        i2 = temp;
    }

    return i2;
}

int main()
{
    climbStairs(6);
    return 1;
}