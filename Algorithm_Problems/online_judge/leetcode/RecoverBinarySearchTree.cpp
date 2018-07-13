/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
#include <algorithm>
#include <numeric>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* first{nullptr};
    TreeNode* second{nullptr};
    TreeNode* prev = new TreeNode(std::numeric_limits<int>::min());

   public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root);
        if (first && second) std::swap(first->val, second->val);
    }

    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        // inorder traversal should traverse a ascending valuesl
        if (!first && node->val <= prev->val) first = prev;
        if (first && node->val <= prev->val) second = node;
        prev = node;
        inorderTraversal(node->right);
    }
};