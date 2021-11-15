#include <vector>
#include <iostream>
#include "LeetcodePrint.h"

using namespace std;

bool hasCycle(ListNode* head)
{
	ListNode* p1, * p2;
	p1 = p2 = head;
	do
	{
		if (!p2 || !p2->next)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next->next;
	} while (p1 != p2);

	return true;
}