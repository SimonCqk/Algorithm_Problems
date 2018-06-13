/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		if (!head || m < 0 || n < m)
			return head;
		ListNode new_head(0);
		ListNode *tmp = nullptr;
		new_head.next = head;
		ListNode* pre = &new_head;
		for (int i = 0; i < m - 1; i++)
			pre = pre->next;
		ListNode* cur = pre->next;
		n -= m;
		while (n-- > 0) {
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		return new_head.next;
	}
};