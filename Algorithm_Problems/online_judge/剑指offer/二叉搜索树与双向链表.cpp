/*
  输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
  要求不能创建任何新节点(空间复杂度为O(1))，只能调整树中节点指针的指向，
*/
#include"predefines.h"

/*
  有序链表其实就是二叉搜索树的中序遍历，遍历的同时要串联前驱和后驱
*/
void ConverNode(BinaryNode<int>* node, BinaryNode<int>** last) {
	if (!node)
		return;
	auto cur = node;
	if (cur->left)
		ConverNode(cur->left, last);
	cur->left = (*last);
	if (*last)
		(*last)->right = cur;
	(*last) = cur;
	if (cur->right)
		ConverNode(cur->right, last);
}

BinaryNode<int>* ConvertToDuLinkedList(BinaryNode<int>* root) {
	if (!root)
		return nullptr;
	BinaryNode<int>* last = nullptr;  // 链表最左端是null
	ConverNode(root, &last);
	auto head = last;
	while (head&&head->left)
		head = head->left;
	return head;
}

// 非递归版本

BinaryNode<int>* ConvertToDuLinkedList_NonRecur(BinaryNode<int>* root) {
	if (!root)
		return nullptr;
	BinaryNode<int>* null = nullptr;  // last刚开始应指向nullptr，但不能直接&(nullptr)，所以借用一个临时变量。
	BinaryNode<int>** last = &null;
	BinaryNode<int>* cur;
	stack<decltype(root)> s;
	while (root || !s.empty()) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else {
			root = s.top();
			cur = root;
			s.pop();
			root = root->right;
			cur->left = (*last);
			if (*last)
				(*last)->right = cur;
			(*last) = cur;
		}
	}
	auto head = (*last);
	while (head&&head->left)
		head = head->left;
	return head;
}

int main() {
	vector<int> tree{ 10,6,14,4,8,12,16 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root,tree);
	auto head = ConvertToDuLinkedList_NonRecur(root);
	while (head) {
		cout << head->value << "->";
		head = head->right;
	}
	cout << "null" << endl;
	// 销毁双向链表
	auto copy = head;
	while (head) {
		head = head->left;
		delete copy; copy = nullptr;
		copy = head;
	}
	return 0;
}