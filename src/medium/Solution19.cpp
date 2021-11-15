//
// Created by 路双宁 on 2021/3/14.
// 删除链表的倒数第 N 个结点
//

#include "StructDefinition.h"

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* fast, *slow;
    slow = fast = head;
    for(int i =0;i<n;i++)
    {
        fast = fast->next;
    }
    if(!fast)
    {
        return slow->next;
    }
    while(fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return head;
}