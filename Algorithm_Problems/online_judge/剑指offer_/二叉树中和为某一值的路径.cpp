/*
  输入一棵二叉树和一个整数，打印出二叉树节点值的和为输入整数的所有路径。
  二叉树的路径：从根节点开始往下一直到叶节点所经过的节点形成的一条路径。
*/

#include"predefines.h"

// 递归版本

void FindPaths(BinaryNode<int>* root, const int& expected,
	vector<int>& path, int cur_sum) {
	cur_sum += root->value;
	path.push_back(root->value);
	// 如果是叶节点且满足条件，打印
	if (cur_sum == expected && ((!root->left) && (!root->right))) {
		std::printf("A path found:\n");
		for (auto& p : path)
			std::printf("%d -> ", p);
		cout << "null" << endl;
	}
	if (root->left)
		FindPaths(root->left, expected, path, cur_sum);
	if (root->right)
		FindPaths(root->right, expected, path, cur_sum);
	// 返回父节点，在路径上删除当前节点
	path.pop_back();
}

void FindPaths(BinaryNode<int>* root, const int& expected) {
	if (!root)
		return;
	vector<int> path;
	int cur_sum = 0;
	FindPaths(root, expected, path, cur_sum);
}

int main() {
	vector<int> tree{ 10,5,12,4,7 };
	BinaryNode<int>* root = new BinaryNode<int>;
	BuildBTree(&root, tree);
	FindPaths(root, 22);
	DestoryBTree(&root);
	return 0;
}