/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
*/
#include<iostream>
#include<vector>
#include"predefines.h"

using namespace std;

ListNode* MergeLinkedList(ListNode* head_one, ListNode* head_two) {
	if (!head_one || !head_two)
		return nullptr;
	// move to the real nodes.
	head_one = head_one->next;
	head_two = head_two->next;
	std::vector<int> merged;
	while (head_one || head_two) {
		if (!head_one&&head_two) {
			while (head_two) {
				merged.push_back(head_two->value);
				head_two = head_two->next;
			}
			break;
		}
		else if (!head_two&&head_one) {
			while (head_one) {
				merged.push_back(head_one->value);
				head_one = head_one->next;
			}
			break;
		}
		if (head_one->value < head_two->value) {
			merged.push_back(head_one->value);
			head_one = head_one->next;
		}
		else {
			merged.push_back(head_two->value);
			head_two = head_two->next;
		}
	}
	ListNode* new_head = new ListNode;
	BuildLinkedList(&new_head, merged);
	return new_head;
}

int main() {
	vector<int> arr1{ 1,4,7,8,11,44,77,88,99 }, arr2{ 2,3,5,6,9 };
	ListNode* head1 = new ListNode, *head2 = new ListNode;
	BuildLinkedList(&head1, arr1);
	BuildLinkedList(&head2, arr2);
	auto new_head = MergeLinkedList(head1, head2);
	PrintLinkedList(new_head);
	DestoryLinkedList(head1);
	DestoryLinkedList(head2);
	DestoryLinkedList(new_head);
	return 0;
}