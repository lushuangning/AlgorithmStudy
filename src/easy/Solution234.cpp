// 回文链表：https://leetcode-cn.com/problems/palindrome-linked-list/

#include <iostream>
#include <vector>
#include <StructDefinition.h>
#include <Vector2Other.h>

using namespace std;

ListNode* reverseList(ListNode* head)
{
	ListNode* p, * n;
	p = nullptr;
	while (head) {
		n = head->next;
		head->next = p;
		p = head;
		head = n;
	}

	return p;
}

bool isPalindrome(ListNode* head) {
	ListNode* mid, *fast, *p;
	fast = mid = head;

	while (fast->next && fast->next->next) {
		mid = mid->next;
		fast = fast->next->next;
	}

	p = reverseList(mid);

	while (head && p){
		if (head->val != p->val) {
			reverseList(mid);
			return false;
		}
		head = head->next;
		p = p->next;
	}

	// 记得返回之前再把后半部分逆序回去
	reverseList(mid);

	return true;
}

int main() {
	vector<int> vec = {1, 2, 3, 3, 2, 2};
	ListNode* list_vec;

	list_vec = buildList(vec);
	cout << isPalindrome(list_vec);
	return 0;
}