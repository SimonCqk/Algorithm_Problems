/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
	ListNode* swapPairs(ListNode* head) {
		if (!head)
			return nullptr;
		auto new_head = new ListNode(0);
		new_head->next = head;
		auto cur = new_head;
		while (cur->next && cur->next->next) {
			auto temp = cur->next->next;
			cur->next->next = temp->next;
			temp->next = cur->next;
			cur->next = temp;
			// move forward 2 steps.
			cur = cur->next->next;
		}
		return new_head->next;
	}
};