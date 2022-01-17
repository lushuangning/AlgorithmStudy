/*
* Created by 路双宁 on 2021 / 3 / 17.
* 两数相加
*/

#include "StructDefinition.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode  *l3, *p;
    int sum, carry = 0;
    l3 = l1;
    while(l1 && l2)
    {
        sum = l1->val + l2->val + carry;
        l1->val = sum%10;
        carry = (sum < 10) ? 0:1;
        p = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(!l1 && l2)
    {
        p->next = l2;
        l1 = l2;
    }
    while(carry==1)
    {
        if(l1)
        {
            sum = l1->val + carry;
            if(sum < 10)
            {
                l1->val = sum;
                carry = 0;
            }
            else
            {
                l1->val = sum%10;
                p = l1;
                l1 = l1->next;
                carry = 1;
            }
        }
        else
        {
            l1 = new ListNode;
            l1->next = nullptr;
            l1->val = carry;
            p->next = l1;
            carry = 0;
        }
    }
    return l3;
}
