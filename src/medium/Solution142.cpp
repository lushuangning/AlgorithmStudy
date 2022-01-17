// �������� II

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

	// �Ѿ�֤���л����������һ�·��ʼ���
	p2 = head;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	} 

	return p1;
}