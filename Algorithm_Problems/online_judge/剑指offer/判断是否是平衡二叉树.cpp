/*
  输入一棵树的根节点，判断该树是否是平衡二叉树。
*/
#include"predefines.h"
#include<algorithm>
/*
  可以利用<二叉树的深度>的解决方案，遍历每个树节点时都调用一次DepthOfBinaryTree,
  但是这样会有大量节点的重复计算，且性能低下
*/

/*
  那么自顶向上，利用后序遍历，在遍历某个节点时，它的左右子树都已经被遍历过了。
*/
bool IsBalanceTree(BinaryNode<int>* root, int& depth) {
	if (!root) {
		depth = 0;
		return true;
	}
	int left, right;
	if (IsBalanceTree(root->left, left) && IsBalanceTree(root->right, right)){
		if (std::abs(left - right) <= 1) {
			depth = (left > right) ? left : right;
			return true;
		}
	}
	return false;
}