// 环形链表 II

#include <vector>
#include <iostream>
#include "LeetcodePrint.h"

using namespace std;

ListNode* detectCycle(ListNode* head)
{
	ListNode *p1, *p2;
	p1 = p2 =  head;

	do
	{
		if (!p2 || !p2->next)
		{
			return nullptr;
		}
		p1 = p1->next;
		p2 = p2->next->next;

	} while (p1 != p2);

	// 已经证明有环，接下来找环路开始结点
	p2 = head;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	} 

	return p1;
}