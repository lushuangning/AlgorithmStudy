#include <iostream>
#include "StructDefinition.h"
#include "LeetcodePrint.h"

DoublyListNode* reverseList(DoublyListNode* head)
{
    DoublyListNode* p, * n;
    p = nullptr;
    while (head) {
        n = head->next;
        head->next = p;
        head->pre = n;
        p = head;
        head = n;
    }

    return p;
}

int main()
{
    DoublyListNode *pointer, *p, *head;
    pointer = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    pointer->val = 5;
    pointer->next = nullptr;
    pointer->pre = nullptr;
    head = p = pointer;
    pointer = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    pointer->val = 6;
    pointer->next = nullptr;
    pointer->pre = p;
    p->next = pointer;
    p = pointer;

    pointer = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    pointer->val = 7;
    pointer->next = nullptr;
    pointer->pre = p;
    p->next = pointer;
    p = pointer;
    
    showListNode(head);
    head = reverseList(head);
    showListNode(head);

	return 0;
}