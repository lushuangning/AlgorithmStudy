/*
* Created by 路双宁 on 2021/3/19.
* 汉明距离
*/

#include <iostream>

int hammingDistance(int x, int y)
{
    int a = x^y, b = 1, num = 0;

    for (int i = 0; i < 31; ++i) {
        if ((a&(b<<i)) != 0){
            ++num;
        }
    }

    return num;
}

int main()
{

    return 1;
}
