/*
* Created by 路双宁 on 2021/3/14.
* 删除链表中的节点
*/

#include "StructDefinition.h"

void deleteNode(ListNode* node)
{
    ListNode* del = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete del;
}

int main()
{

    return 1;
}