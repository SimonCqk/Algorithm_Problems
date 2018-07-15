/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
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
    using iter = vector<int>::const_iterator;

   public:
    TreeNode* buildTree(const vector<int>& preorder,
                        const vector<int>& inorder) {
        if (preorder.size() != inorder.size() || preorder.empty())
            return nullptr;
        return buildTreeCore(preorder.begin(), preorder.end(), inorder.begin(),
                             inorder.end());
    }

   private:
    TreeNode* buildTreeCore(iter preStart, iter preEnd, iter inStart,
                            iter inEnd) {
        int rootVal = *preStart;
        auto root = new TreeNode(rootVal);
        if (preStart == preEnd) {
            return root;
        }
        auto inRoot = inStart;
        while (inRoot != inEnd && (*inRoot) != rootVal) ++inRoot;
        int leftLen = inRoot - inStart;
        auto leftPreEnd = preStart + leftLen;
        if (leftLen > 0) {
            // construct left subtree
            root->left =
                buildTreeCore(preStart + 1, leftPreEnd, inStart, inRoot - 1);
        }
        if (leftLen < preEnd - preStart) {
            // right subtree still can exist
            root->right =
                buildTreeCore(leftPreEnd + 1, preEnd, inRoot + 1, inEnd);
        }
        return root;
    }
};