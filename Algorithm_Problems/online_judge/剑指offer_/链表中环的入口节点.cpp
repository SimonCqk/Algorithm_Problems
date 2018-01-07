/*
 如果一个链表中包含环，如何找出环的入口节点？
*/
#include"predefines.h"

// 找到链表环中相遇的结点
ListNode* MeetingNode(ListNode* head) {
	if (!head || !head->next)
		return nullptr;
	ListNode* pslow = head->next;
	ListNode* pfast = pslow->next;
	while (pslow&&pfast) {
		if (pfast == pslow)
			return pfast;
		pslow = pslow->next;
		if (pfast->next)
			pfast = pfast->next;
	}
	return nullptr;  // 链表中没有环
}

// 得出环中节点的个数，进而找到入口
ListNode* EntryOfLoop(ListNode* head) {
	auto meet = MeetingNode(head);
	if (!meet)
		return nullptr;
	size_t count = 1;
	auto start = meet;
	while (start->next != meet) {
		++count;
		start = start->next;
	}
	/*
	  从头结点开始walk,第一个结点先走count步,
	  之后两个节点同步走，相遇点即环的入口
	*/
	ListNode* fast = head;
	for (size_t i = 0; i < count; ++i)
		fast = fast->next;
	ListNode* slow = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
