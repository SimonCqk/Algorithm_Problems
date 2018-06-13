/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include<vector>
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (!notAllNull(lists) || lists.empty())
			return NULL; // all null pointer.
		if (lists.size() == 1)
			return lists[0];
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		vector<ListNode*> new_lists;
		for (int i = 0; i < lists.size(); ++i)
			if (lists[i])
				new_lists.push_back(lists[i]);
		while (notAllNull(new_lists)) {
			int index = 0;
			int min;
			for (; index < new_lists.size(); ++index) {
				if (new_lists[index]) {
					min = new_lists[index]->val; break;
				}
			}
			// find min.
			for (int i = index + 1; i < new_lists.size(); ++i) {
				if (new_lists[i] && new_lists[i]->val < min) {
					min = new_lists[i]->val;
					index = i;
				}
			}
			ans->next = new ListNode(new_lists[index]->val);
			new_lists[index] = new_lists[index]->next;
			ans = ans->next;
		}
		return head->next;
	}
	bool notAllNull(vector<ListNode*>& lists) {
		for (auto list : lists) {
			if (list)
				return true;
		}
		return false;
	}
};

int main() {
	ListNode* l1 = NULL;
	ListNode head(0);
	head.next = new ListNode(1);
	vector<ListNode*> vec{ l1,head.next };
	Solution s;
	ListNode* ans = s.mergeKLists(vec);
	while (ans != NULL) {
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}