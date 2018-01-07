/*
 输入一个链表，输出该链表中倒数第k个节点。
*/

#include<iostream>
#include<vector>
#include"predefines.h"

using namespace std;



ListNode* FindKthToTail(ListNode* head, int k) {
	if (!head||k<=0)
		return nullptr;
	ListNode* node = head;
	while (k-- >= 0) {
		if (!node)
			return nullptr;
		node = node->next;
	}
	ListNode* aim = head;
	while (node) {
		aim = aim->next;
		node = node->next;
	}
	return aim;
}

int main() {
	vector<int> arr{ 1,2,3,4,5,6,7 };
	ListNode* head = new ListNode;
	BuildLinkedList(&head, arr);
	auto res = FindKthToTail(head, 3);
	cout << res->value << endl;
	DestoryLinkedList(head);
	return 0;
}