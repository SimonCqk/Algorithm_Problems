/*
Given a binary tree, return the zigzag level order traversal of its nodes'
values. (ie, from left to right, then right to left for the next level and
alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        stack<TreeNode *> levels[2];
        int cur = 0, next = 1;
        levels[cur].push(root);
        while (!levels[0].empty() || !levels[1].empty()) {
            auto node = levels[cur].top();
            levels[cur].pop();
            tmp.push_back(node->val);
            if (cur == 0) {
                if (node->left) levels[next].push(node->left);
                if (node->right) levels[next].push(node->right);
            } else {
                if (node->right) levels[next].push(node->right);
                if (node->left) levels[next].push(node->left);
            }
            if (levels[cur].empty()) {
                res.push_back(std::move(tmp));
                cur = 1 - cur;  // 1->0 / 0->1
                next = 1 - next;
            }
        }
        return res;
    }
};