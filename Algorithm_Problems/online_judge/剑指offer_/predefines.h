#ifndef PRE_DEFINES_H
#define PRE_DEFINES_H
#include<vector>
#include<iostream>
using std::vector;

struct ListNode
{
	int value;
	ListNode* next;

	ListNode()
		:next(nullptr) {}

	ListNode(const int& val)
		:value(val), next(nullptr) {}
};

void BuildLinkedList(ListNode** head, const vector<int>& arr) {
	if (head == nullptr || *head == nullptr || arr.empty())
		return;
	for (const int& i : arr) {
		(*head)->next = new ListNode(i);
		head = &(*head)->next;
	}
}

void PrintLinkedList(ListNode* head) {
	if (!head)
		return;
	while (head->next) {
		head = head->next;
		std::printf("%d ", head->value);
	}
}

void DestoryLinkedList(ListNode* head) {
	if (!head || !head->next)
		return;
	ListNode* cur = head;
	ListNode* next = head->next;
	while (next) {
		delete cur; cur = nullptr;
		cur = next;
		next = next->next;
	}
}

template<typename T>
struct BinaryNode
{
	T value;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(const T& val)
		:value(val), left(nullptr), right(nullptr) {}
	BinaryNode()
		:left(nullptr), right(nullptr) {}
};


/*
  注意传入的是指针的指针，否则不会生效(临时变量自动销毁).
*/
template<typename T>
void BuildBTree(BinaryNode<T>** node, const vector<T>& preorder,size_t index) {
	if (preorder.empty() || index >= preorder.size())
		return;
	else {
		*node = new BinaryNode<T>(preorder[index++]);
		BuildBTree(&(*node)->left, preorder,index);
		BuildBTree(&(*node)->right, preorder,index);
	}
}

template<typename T>
void PrintBTree_Pre(BinaryNode<T>* node) {
	if (node) {
		std::cout << node->value << std::endl;
		PrintBTree_Pre(node->left);
		PrintBTree_Pre(node->right);
	}
}

template<typename T>
void DestoryBTree(BinaryNode<T>** node) {
	if (*node) {
		DestoryBTree(&(*node)->left);
		DestoryBTree(&(*node)->right);
		delete (*node); (*node) = nullptr;
	}
}


#endif // !PRE_DEFINES_H
