/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
2
/ \
1   3
Output: true
Example 2:

 5
/ \
1   4
   / \
  3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
is 5 but its right child's value is 4.
*/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, nullptr, nullptr);
	}
	bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
		if (!root)
			return true;
		bool flag = true;
		if (root->left)
			flag = (root->val > root->left->val);
		if (root->right)
			flag = flag && (root->val < root->right->val);
		if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
			return false;
		return flag && isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
	}
};