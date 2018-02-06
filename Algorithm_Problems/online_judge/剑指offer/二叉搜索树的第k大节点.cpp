/*
  给定一棵二叉搜索树，请找出其第k大的节点。
*/

/*
  二叉搜索树的中序遍历即是递增排序数组。
*/
#include"predefines.h"


BinaryNode<int>* GetKthNodeCore(BinaryNode<int>* root, int& k) {
	BinaryNode<int>* ans = nullptr;
	if (root->left)
		ans = GetKthNodeCore(root->left, k);
	if (!ans) {
		if (k == 1)
			ans = root;
		--k;
	}
	if (!ans && root->right)
		ans = GetKthNodeCore(root->right, k);
	return ans;
}

BinaryNode<int>* GetKthNode(BinaryNode<int>* root, int k) {
	if (!root || k <= 0)
		return nullptr;
	return GetKthNodeCore(root, k);
}

int main() {
	vector<int> nums{ 5,3,7,2,4,6,8 };
	BinaryNode<int>* root = nullptr;
	BuildBTree(&root, nums);
	std::printf("%d\n", GetKthNode(root, 3)->value);
	return 0;
}