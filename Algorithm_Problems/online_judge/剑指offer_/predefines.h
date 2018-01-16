#ifndef PRE_DEFINES_H
#define PRE_DEFINES_H
#include<vector>
#include<iostream>
#include<queue>
using std::vector;
using std::cout;
using std::endl;


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
  二叉树是层序输入.
*/
template<typename T>
void BuildBTree(BinaryNode<T>** node, const vector<T>& levelorder, size_t index = 0) {
	if (levelorder.empty() || index >= levelorder.size())
		return;
	else {
		*node = new BinaryNode<T>(levelorder[index]);
		BuildBTree(&(*node)->left, levelorder, 2 * index + 1);
		BuildBTree(&(*node)->right, levelorder, 2 * index + 2);
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
void PrintByLevelOrder(BinaryNode<T>* root) {
	queue<BinaryNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		std::cout << cur->value << ' ';
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	std::cout << std::endl;
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
