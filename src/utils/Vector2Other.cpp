//
// Created by 路双宁 on 2021/3/17.
//

#include "Vector2Other.h"
#include <vector>

TreeNode* createNode(std::vector<int>& vec, int index);

/*
 *
 * 由于力扣给的结构体中，val的类型是int，因此此处都是基于int构建的链表
 *
 */
ListNode* buildList(std::vector<int> &vec)
{   //构造不带头结点的链表，尾插法
    ListNode *list = new ListNode(-1);  //哑结点
    ListNode *p, *q;

    q = list;

    for (int i = 0; i < vec.size(); ++i) 
    {
        p = (ListNode *)malloc(sizeof (ListNode));
        if (p)
        {
            p->val = vec[i];
            p->next = nullptr;
            q->next = p;
            q = p;
        }
    }

    return list->next;
}

TreeNode* buildBinTree(std::vector<int>& vec)
{
    return createNode(vec, 0);
}

TreeNode* createNode(std::vector<int>& vec, int index)
{
    TreeNode* node = nullptr;

    if (index < vec.size() && vec[index] != -1)
    {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        if (node)   //分配成功
        {
            node->val = vec[index];
            node->left = createNode(vec, ++index);
            node->right = createNode(vec, ++index);
        }
    }

    return node;
}