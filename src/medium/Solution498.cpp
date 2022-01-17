/*
* Created by 路双宁 on 2021/3/17.
* 对角线遍历
*/

#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
    int m,n,p,q;
    vector<int> tmp;
    m = matrix.size();
    if (m<=0)
        return tmp;
    n = matrix[0].size();
    if (n<=0)
        return tmp;
    p = q =0;
    bool flag = true;

    tmp.push_back(matrix[0][0]);
    for (int i=1;i<m*n;i++) 
    {
        if (flag)
        {
            if(p-1<0 || q+1>n-1)
            {
                if (p-1<0 && q+1<=n-1)
                {
                    q+=1;
                }
                else
                {
                    p+=1;
                }
                flag = false;
            }
            else
            {
                p-=1;
                q+=1;
            }
        }
        else
        {
            if (p+1>m-1 || q-1<0)
            {
                if (p+1>m-1 && q-1<n-1)
                {
                    q+=1;
                }
                else
                {
                    p+=1;
                }
                flag = true;
            }
            else
            {
                p+=1;
                q-=1;
            }
        }
        tmp.push_back(matrix[p][q]);
    }
    return tmp;
}
