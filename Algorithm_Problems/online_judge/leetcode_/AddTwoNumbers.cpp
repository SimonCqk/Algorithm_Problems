/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

// 342 + 465 = 807

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include<iostream>
#include<vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL)
			return NULL;
		int carry = 0; // carry == 1 may happen.
		ListNode* ans = new ListNode(-1); // head node.
		ListNode* ans_ = ans; // record head node.
		while (l1 != NULL || l2 != NULL){
			if (l1 != NULL){
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL){
				carry += l2->val;
				l2 = l2->next;
			}
			ans->next = new ListNode(carry % 10);
			ans = ans->next; // move the pointer.
			carry /= 10;
		}
		if (carry == 1)
			ans->next = new ListNode(1);
		return ans_->next;
	}
};
