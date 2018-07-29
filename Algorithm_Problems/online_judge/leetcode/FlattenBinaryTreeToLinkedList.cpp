/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
#include<stack>

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
    void flatten(TreeNode *root) {
        if (!root) return;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *prev = nullptr, *cur = nullptr;
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
            cur->left = nullptr;
            if (prev) prev->right = cur;
            prev = cur;
        }
    }
};