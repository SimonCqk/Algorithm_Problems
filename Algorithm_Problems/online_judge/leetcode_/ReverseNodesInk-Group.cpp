/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k <= 1)
			return head;
		ListNode* preheader = new ListNode(0);
		preheader->next = head;
		int length = 0;
		ListNode* cur = preheader;
		while (cur = cur->next)
			++length;

		ListNode* pre = preheader, *next;
		while (length >= k) {
			int count = k;
			cur = pre->next;
			next = cur->next;
			// do reverse the list
			while (--count > 0) {
				cur->next = next->next;
				next->next = pre->next;
				pre->next = next;
				next = cur->next;
			}
			pre = cur;
			length -= k;
		}
		return preheader->next;
	}
};