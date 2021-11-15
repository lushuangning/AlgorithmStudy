#include <vector>
#include <iostream>
#include "StructDefinition.h"
#include "LeetcodePrint.h"

using namespace std;

vector<int> reversePrint(ListNode* head);

vector<int> reversePrint(ListNode* head) {
	ListNode* pre = nullptr;
	ListNode* next;
	vector<int> vec;

	while (head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;	
	}

	while (pre) 
	{
		vec.push_back(pre->val);
		pre = pre->next;
	}

	return vec;
}

int main()
{
	ListNode* head = nullptr;
	ListNode* tmp = nullptr;

	head = new ListNode(8);
	tmp = new ListNode(9);
	head->next = tmp;
	tmp->next = new ListNode(10);
	tmp = tmp->next;

	//showNodeList(head);

	vector<int> vec = reversePrint(head);
	
	show1DVector(vec);

	return 0;
}