//
// Created by 路双宁 on 2021/3/17.
//

#ifndef LEET_CODE_STRUCTDEFINITION_H
#define LEET_CODE_STRUCTDEFINITION_H

// 单链表
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双链表
typedef struct DoublyListNode
{
    int val;
    DoublyListNode* pre;
    DoublyListNode* next;
    DoublyListNode() : val(0), pre(nullptr), next(nullptr) {}
    DoublyListNode(int x) : val(x), pre(nullptr), next(nullptr) {}
    DoublyListNode(int x, DoublyListNode* p, DoublyListNode* n) : val(x), pre(p), next(n) {}
}DoublyListNode;

// 带随机指针的单链表
struct RandomNode {
    int val;
    struct RandomNode* next;
    struct RandomNode* random;
    RandomNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

// 二叉树
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#endif //LEET_CODE_STRUCTDEFINITION_H
