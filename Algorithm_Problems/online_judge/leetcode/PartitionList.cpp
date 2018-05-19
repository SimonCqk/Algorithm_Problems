/*
Given a linked list and a value x, partition it such that all nodes less

than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
#include<algorithm>
#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		/* head(not head->next) donates first element */
		if (!head || !head->next)
			return head;
		ListNode *cur = head->next, *prev = head, *work = head->next;
		while (cur) {
			if (cur->val < x) {
				if (cur == work) {
					work = work->next; prev = prev->next; cur = cur->next;
					continue;
				}
				prev->next = cur->next;
				if (work->next != cur) {
					cur->next = work->next;
					work->next = cur;
				}
				std::swap(cur->val, work->val);
				work = work->next;
				cur = prev->next;
			}
			else {
				prev = prev->next; cur = cur->next;
			}
		}
		return head;
	}
};
