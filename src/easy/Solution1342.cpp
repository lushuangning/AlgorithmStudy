/*
* Created by 路双宁 on 2021/3/14.
* 将数字变成 0 的操作次数
*/

int numberOfSteps (int num)
{
    int count = 0;

    while (num)
    {
        if ((num&1) == 0) 
        {
            num = num >> 1;
        }
        else
        {
            num--;
        }
        count++;
    }

    return count;
}

int main()
{

    return 1;
}