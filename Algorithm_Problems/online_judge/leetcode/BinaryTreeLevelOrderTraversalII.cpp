/*
Given a binary tree, return the bottom-up level order traversal of its nodes'
values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> ans;
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) {
                ans.push_back(std::move(tmp));
                tmp.clear();
                if (!q.empty()) q.push(nullptr);
                continue;
            }
            tmp.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};