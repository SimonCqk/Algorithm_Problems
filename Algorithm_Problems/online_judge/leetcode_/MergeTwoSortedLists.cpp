/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL&&l2 == NULL)
			return NULL;
		else if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		while (l1 != NULL&&l2 != NULL) {
			if (l1->val < l2->val) {
				ans->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else {
				ans->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			ans = ans->next;
		}
		while (l1 != NULL) {
			ans->next = new ListNode(l1->val);
			ans = ans->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			ans->next = new ListNode(l2->val);
			ans = ans->next;
			l2 = l2->next;
		}
		return head->next;
	}
};