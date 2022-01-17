/*
* Created by 路双宁 on 2021/3/16.
* 合并两个有序链表
*/

#include "StructDefinition.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *p = new ListNode(-1); //哑结点
    ListNode *q = p;

    if(nullptr == l1 || nullptr == l2)
        return l1 == nullptr?l2:l1;

    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            q->next = l1;
            l1 = l1->next;
        }
        else
        {
            q->next = l2;
            l2 = l2->next;
        }
        q = q->next;
    }

    q->next = (l2 == nullptr)?l1:l2;

    return p->next;
}

int main() 
{

    return 1;
}