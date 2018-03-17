/*
  RT.
*/
#include"predefines.h"

/*
  如果是二叉搜索树，那么是经过排序的。
  如果当前节点的值比两个节点的值都大，那么最低公共父节点一定在当前节点的左子树下。
  .............................小，................................右......
  若当前节点的值在两个节点的值中间，那么便是最低公共父节点。
*/

template<typename T>
BinaryNode<T>* LowestCommonAncestorOfBST(BinaryNode<T>* root, BinaryNode<T>* lhs, BinaryNode<T>* rhs) {
	if (!root || !lhs || !rhs)
		return nullptr;
	if (lhs->value > rhs->value)
		std::swap(lhs, rhs);
	auto cur = root;
	while (cur && (cur->value > rhs->value || cur->value < lhs->value)) {
		if (cur->value > rhs->value)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return cur;
}

