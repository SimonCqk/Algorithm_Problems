/*
 输入一个链表，输出该链表中倒数第k个节点。
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
	int value;
	ListNode* next;

	ListNode()
		:next(nullptr) {}

	ListNode(const int& val)
		:value(val), next(nullptr) {}
};

void BuildLinkedList_test(ListNode** head, const vector<int>& arr) {
	if (head == nullptr || *head == nullptr)
		return;
	for (const int& i : arr) {
		(*head)->next = new ListNode(i);
		head = &(*head)->next;
	}
}

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
	BuildLinkedList_test(&head, arr);
	auto res = FindKthToTail(head, 3);
	cout << res->value << endl;
	return 0;
}