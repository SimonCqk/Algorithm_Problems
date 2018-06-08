/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
#include<vector>
#include<memory>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode **cur = &head, *tmp = nullptr,*next=nullptr;
		while (*cur) {
			if ((*cur)->next && (*cur)->next->val == (*cur)->val) {
				tmp = *cur;
				int tmp_val = (*cur)->val;
				while (tmp && (tmp_val == tmp->val)) {
					next = tmp->next;
					delete tmp; tmp = nullptr;
					tmp = next;
				}
				*cur = tmp;
			}
			else
				cur = &((*cur)->next);
		}

		return head;
	}
};

int main() {
	ListNode* head = new ListNode(1);
	vector<int> nums{ 2,3,3,4,4,5 };
	auto cur = head;
	for (int num : nums) {
		cur->next = new ListNode(num);
		cur = cur->next;
	}
	Solution s;
	head = s.deleteDuplicates(head);
	while (head) {
		std::printf("%d ", head->val);
		head = head->next;
	}
	return 0;
}