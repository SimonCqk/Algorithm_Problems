/*
 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
*/

#include"predefines.h"
#include<iostream>
#include<vector>

using namespace std;

ListNode* ReverseLinkedList(ListNode* head) {
	ListNode* prev = nullptr, *cur = head->next, *next = nullptr;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	ListNode* new_head = new ListNode;
	new_head->next = prev;
	return new_head;
}

int main() {
	vector<int> arr{ 1,2,3,4,5,6,7,8,9 };
	ListNode* head = new ListNode;
	BuildLinkedList(&head, arr);
	PrintLinkedList(head);
	cout << endl;
	head = ReverseLinkedList(head);
	PrintLinkedList(head);
	DestoryLinkedList(head);
	return 0;
}