/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]

*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)
			return {};
		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);
		vector<vector<int>> ans;
		vector<int> tmp;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (!cur) {
				ans.push_back(std::move(tmp));
				tmp.clear();
				if (!q.empty())
					q.push(nullptr);
				continue;
			}
			tmp.push_back(cur->val);
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
		return ans;
	}
};
