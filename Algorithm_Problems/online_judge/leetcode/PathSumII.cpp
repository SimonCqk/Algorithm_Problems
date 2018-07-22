/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        _hasPathSum(res, {}, root, 0, sum);
        return res;
    }

   private:
    void _hasPathSum(vector<vector<int>> &res, vector<int> curPath,
                     TreeNode *node, int curSum, const int &sum) {
        if (!node) return;
        curSum += node->val;
        curPath.push_back(node->val);
        if (!node->left && !node->right && curSum == sum)
            res.push_back(curPath);
        _hasPathSum(res, curPath, node->left, curSum, sum);
        _hasPathSum(res, curPath, node->right, curSum, sum);
    }
};