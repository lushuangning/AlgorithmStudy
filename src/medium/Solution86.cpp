// �ָ�����https://leetcode-cn.com/problems/partition-list/

#include <iostream>
#include <vector>
#include <StructDefinition.h>
#include <Vector2Other.h>
#include <LeetcodePrint.h>

using namespace std;

ListNode* partition(ListNode* head, int x) {
	// n��ʾС��x������ͷ��m��ʾ���ڵ���x��ͷ
	// less��ʾС��x��β��eq_more��ʾ����x��β
	ListNode* less = nullptr, * eq_more = nullptr, *p, *m = nullptr, *n = nullptr;
	p =  head;
	while (p) {
		if (p->val < x){
			if (less)
				less->next = p;
			less = p;

			if (!n)
				n = less;
		}
		else {
			if (eq_more)
				eq_more->next = p;
			eq_more = p;

			if (!m)
				m = eq_more;
		}
		p = p->next;

		if (eq_more)
			eq_more->next = nullptr;

		if (less)
			less->next = nullptr;
	}

	if (less && m)
		less->next = m;

	return n?n:m;
}

int main() {
	vector<int> vec = { 2,1 };
	ListNode* list;
	list = buildList(vec);
	showListNode(partition(list, 2));
	return 0;
}