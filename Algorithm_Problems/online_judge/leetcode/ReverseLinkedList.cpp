/*
Reverse a singly linked list.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* first = head;
		while (first) {
			auto tmp = first->next;
			first->next = prev;
			prev = first;
			first = tmp;
		}
		return prev;  // prev is new head
	}
};

ListNode* reverseList(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* p = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return p;
}