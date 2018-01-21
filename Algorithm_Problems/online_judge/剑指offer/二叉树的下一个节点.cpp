/*
给定一个二叉树和其中一个节点，如何找出中序遍历序列的下一个节点？
树的节点除了有两个分别指向左，右子节点的指针，还有一个指向父节点的指针。
*/

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left, *right, *parent;
	BinaryTreeNode(const int& val)
		:value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

BinaryTreeNode* GetNextNode(BinaryTreeNode* node) {
	if (!node)
		return nullptr;
	BinaryTreeNode* pnext = nullptr;
	if (node->right) {
		BinaryTreeNode* pright = node->right;
		while (pright->left)
			pright = pright->left;
		pnext = pright;
	}
	else if (node->parent) {
		BinaryTreeNode* cur = node;
		BinaryTreeNode* parent = node->parent;
		while (parent&&cur == parent->right) {
			cur = parent;
			parent = parent->parent;
		}
		pnext = parent;
	}
	return pnext;
}