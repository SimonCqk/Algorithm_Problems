/*
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.

*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};



class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (!head || !head->next || !k) 
			return head;
		auto cur = head;
		int len = 1;
		while (cur->next && ++len)
			cur = cur->next;
		cur->next = head;
		k = len - k % len;
		while (k--) 
			cur = cur->next;
		head = cur->next;
		cur->next = nullptr;
		return head;
	}
};