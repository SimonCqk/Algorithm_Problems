/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // NOT ACCEPTED.
        if (inorder.size() != postorder.size() || inorder.empty())
            return nullptr;
        return buildTreeCore(inorder.begin(), inorder.end(), postorder.begin(),
                             postorder.end());
    }

   private:
    TreeNode* buildTreeCore(iter inBeg, iter inEnd, iter postBeg,
                            iter postEnd) {
        int rootVal = *postEnd;
        auto root = new TreeNode(rootVal);
        if (postBeg == postEnd) {
            return root;
        }
        auto inRoot = inBeg;
        while (inRoot != inEnd && (*inRoot) != rootVal) ++inRoot;
        int leftLen = inRoot - inBeg;
        auto leftInEnd = postBeg + leftLen;
        if (leftLen > 0) {
            root->left =
                buildTreeCore(inBeg, inRoot - 1, postBeg + 1, leftInEnd);
        }
        if (leftLen < postEnd - postBeg) {
            root->right =
                buildTreeCore(inRoot + 1, inEnd, leftInEnd + 1, postEnd);
        }
        return root;
    }
};