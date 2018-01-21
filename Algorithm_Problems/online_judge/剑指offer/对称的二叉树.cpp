/*
 实现一个函数，用来判断一棵二叉树是不是对称的。
 如果一个二叉树和它的镜像一样，那么它是对称的。
*/
#include"predefines.h"

bool IsSymmetrical(BinaryNode<int>* lhs, BinaryNode<int>* rhs);

bool IsSymmetrical(BinaryNode<int>* root) {
	return IsSymmetrical(root, root);
}

bool IsSymmetrical(BinaryNode<int>* lhs, BinaryNode<int>* rhs) {
	if (!lhs && !rhs)
		return true;
	if (!lhs || !rhs)
		return false;
	if (lhs->value != rhs->value)
		return false;
	return IsSymmetrical(lhs->left, rhs->right) &&
		IsSymmetrical(lhs->right, rhs->left);
}

int main() {
	vector<int> arr{ 8,6,6,5,7,7,5};
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree<int>(&root,arr);
	std::cout << IsSymmetrical(root) << std::endl;
	DestoryBTree(&root);
	return 0;
}