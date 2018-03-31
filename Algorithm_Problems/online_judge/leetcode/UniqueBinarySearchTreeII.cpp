/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (!n)
			return {};
		return generateCore(1, n);
	}
	vector<TreeNode*> generateCore(int start, int end) {
		vector<TreeNode*> ans;
		if (start > end) {
			ans.push_back(nullptr);
			return ans;
		}
		for (int i = start; i <= end; ++i) {
			auto left_sub = generateCore(start, i - 1);
			auto right_sub = generateCore(i + 1, end);
			for (auto left : left_sub)
				for (auto right : right_sub) {
					auto root = new TreeNode(i);
					root->left = left;
					root->right = right;
					ans.push_back(root);
				}
		}
		return ans;
	}
};