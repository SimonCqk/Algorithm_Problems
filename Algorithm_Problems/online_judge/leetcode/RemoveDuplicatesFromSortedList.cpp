/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode *cur = head, *next = nullptr,*nnext=nullptr;
		while (cur) {
			next = cur->next;
			while (next && (cur->val == next->val)) {
				nnext = next->next;
				delete next;
				next = nnext;
			}
			cur->next = next;
			cur = cur->next;
		}
		return head;
	}
};