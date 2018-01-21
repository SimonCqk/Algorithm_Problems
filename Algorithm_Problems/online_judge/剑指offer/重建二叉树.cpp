/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
*/
#include<iostream>
#include<vector>
#include<exception>

typedef std::vector<int>::iterator iter;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(const int& val) :
		value(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode* ConstructCore(iter preorder_start, iter preorder_end,
	iter inorder_start, iter inorder_end) {
	auto root_val = *preorder_start;
	BinaryTreeNode* root = new BinaryTreeNode(root_val);
	if (preorder_start == preorder_end) {
		if (*preorder_start == *preorder_end)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	auto inorder_root = inorder_start;
	while (inorder_root != inorder_end&&*inorder_root != root_val)
		++inorder_root;
	if (inorder_root == inorder_end&&*inorder_root != root_val)
		throw std::exception("Invalid input");
	int left_length = inorder_root - inorder_start;
	auto left_end = preorder_start + left_length;
	if (left_length > 0) {
		//构建左子树
		root->left = ConstructCore(preorder_start + 1, left_end, inorder_start, inorder_root - 1);
	}
	if (left_length < (preorder_end - preorder_start)) {
		//构建右子树
		root->right = ConstructCore(left_end + 1, preorder_end, inorder_root + 1, inorder_end);
	}
	return root;
}

BinaryTreeNode* Construct(iter preorder, iter inorder, const int& len) {
	if (len <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + len - 1, inorder, inorder + len - 1);
}

void PostOrderPrint(BinaryTreeNode* root) {
	if (!root)
		return;
	PostOrderPrint(root->left);
	PostOrderPrint(root->right);
	std::cout << root->value << ' ';
}

int main() {
	std::vector<int> pre_order, in_order;
	int n;
	std::cout << "Input the number of nodes." << std::endl;
	std::cin >> n;
	std::cout << "Input preoder/inorder sequences of Binary Tree." << std::endl;
	for (int i = 0; i < n; ++i) {
		int item;
		std::cin >> item;
		pre_order.push_back(item);
	}
	for (int i = 0; i < n; ++i) {
		int item;
		std::cin >> item;
		in_order.push_back(item);
	}
	BinaryTreeNode* root= Construct(pre_order.begin(), in_order.begin(), n);
	// 后序遍历输出
	PostOrderPrint(root);
	std::cout << std::endl;
	return 0;
}