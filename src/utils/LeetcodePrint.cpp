//
// Created by 路双宁 on 2021/3/17.
//
#include "LeetcodePrint.h"

using namespace std;

void showNodeList(ListNode* list)
{
    if (!list)
    {
        std::cout << "Empty list!" << std::endl;
        return ;
    }

    while (list->next)
    {
        std::cout << list->val << "->";
        list = list->next;
    }

    std::cout << list->val << std::endl;
}

void show2DVector(vector<vector<int>> &matrix)
{
    int m, n;
    m = matrix.size();
    if (m == 0)
    {
        std::cout << "Empty matrix!" << std::endl;
        return ;
    }

    n = matrix[0].size();
    if (n == 0)
    {
        std::cout << "Empty matrix!" << std::endl;
        return ;
    }

    std::cout << "[" << std::endl;

    for (int i = 0; i < m; ++i) 
    {
        std::cout << "\t[";
        for (int j = 0; j < n-1; ++j) 
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << matrix[i][n-1] << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

void show1DVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i) {cout << vec[i] << "\t";}
    cout << "\n";
}