/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//递归版本
TreeNode* inverse(TreeNode* root) {
	if (root == nullptr)
		return nullptr;

	TreeNode* pNode = root->left;
	root->left = inverse(root->right);
	root->right = inverse(pNode);

	return root;
}

//非递归版本
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			TreeNode* pNode = que.front();
			que.pop();

			TreeNode* pLeft = pNode->left;
			pNode->left = pNode->right;
			pNode->right = pLeft;

			if (pNode->left != NULL)
				que.push(pNode->left);
			if (pNode->right != NULL)
				que.push(pNode->right);
		}
		return root;
	}
};
