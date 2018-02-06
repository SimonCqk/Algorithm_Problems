/*
  RT.
*/
#include"predefines.h"

size_t DepthOfBinaryTree(BinaryNode<int>* root) {
	if (!root)
		return 0;
	size_t ld = DepthOfBinaryTree(root->left);
	size_t rd = DepthOfBinaryTree(root->right);
	return (ld > rd) ? ld + 1 : rd + 1;
}

int main() {
	vector<int> nums{ 1,2,3,4,5,6,7 };
	BinaryNode<int>* root = nullptr;
	BuildBTree(&root, nums);
	std::printf("%d\n", DepthOfBinaryTree(root));
	return 0;
}
