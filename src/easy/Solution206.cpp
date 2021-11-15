//
// Created by 路双宁 on 2021/3/17.
//
#include "StructDefinition.h"

ListNode* reverseList(ListNode* head)
{
    ListNode *p, *n;
    p = nullptr;
    while(head){
        n = head->next;
        head->next=p;
        p=head;
        head=n;
    }
    return p;
}