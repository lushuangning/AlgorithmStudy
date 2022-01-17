// 复制带随机指针的链表 https://leetcode-cn.com/problems/copy-list-with-random-pointer/

#include <iostream>
#include <unordered_map>
#include "StructDefinition.h"
#include "LeetcodePrint.h"

using namespace std;

RandomNode* copyRandomList(RandomNode* head)
{
	RandomNode* n = head;
	RandomNode* tmp = nullptr;
	unordered_map<RandomNode*, RandomNode*>::const_iterator got;
	unordered_map<RandomNode*, RandomNode*>::const_iterator got_next;
	unordered_map<RandomNode*, RandomNode*>::const_iterator got_rand;

	unordered_map<RandomNode*, RandomNode*> map;
	while (n)
	{
		if (tmp = (RandomNode*)malloc(sizeof(RandomNode))) 
		{
			tmp->val = n->val;
			tmp->next = nullptr;
			tmp->random = nullptr;
			map.insert(n, tmp);
		}
		n = n->next;
	}

	n = head;

	while (n) 
	{
		got = map.find(n);
		got_next  = map.find(n->next);
		got_rand = map.find(n->random);

		if (got_next != map.end())
		{
			got->second->next = got_next->second;
		}

		if (got_rand != map.end())
		{
			got->second->random = got_rand->second;
		}

		n = n->next;
	}
}

int main() {
	RandomNode* head, *p, *q;
	p = (RandomNode*)malloc(sizeof(RandomNode));
	q = head = p;
	p->val = 1;
	p->next = nullptr;
	p->random = nullptr;

	p = (RandomNode*)malloc(sizeof(RandomNode));
	p->val = 2;
	p->next = nullptr;
	p->random = nullptr;
	q->next = p;
	q = p;

	p = (RandomNode*)malloc(sizeof(RandomNode));
	p->val = 3;
	p->next = nullptr;
	p->random = nullptr;
	q->next = p;
	q = p;
	head->random = q;

	return 0;
}