/*
* Created by 路双宁 on 2021/3/17.
* 旋转图像
*/

#include <vector>
using namespace std;

/*
 * 法一：先矩阵转置，然后对称交换
 */

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // 矩阵转置
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // 沿左右对称方向交换
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n/2; ++j)
        {
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
}

/*
 * 法二：
 */

//void rotate(vector<vector<int>>& matrix){
//
//}

void counter_rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // 矩阵转置
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // 沿上下对称方向交换
    for (int i = 0; i < n/2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            swap(matrix[i][j], matrix[n-i-1][j]);
        }
    }
}