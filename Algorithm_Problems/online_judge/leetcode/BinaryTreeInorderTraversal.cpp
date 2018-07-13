/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
 \
  2
 /
3

Output: [1,3,2]
*/
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> nums;
        inorder(nums, root);
        return nums;
    }

    void inorder(vector<int>& nums, TreeNode* cur) {
        nums.push_back(cur->val);
        if (cur->left) inorder(nums, cur->left);
        if (cur->right) inorder(nums, cur->right);
    }

    vector<int> inorderTraversalNonrecursive(TreeNode* root) {
        if (!root) return {};
        vector<int> nums;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                nums.push_back(cur->val);
                cur = cur->right;
            }
        }
        return nums;
    }
};