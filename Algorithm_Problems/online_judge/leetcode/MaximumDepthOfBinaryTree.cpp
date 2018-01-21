/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return findNext(root,1);
    }
    int findNext(TreeNode* node,int cur_depth){
        if(!node||(!node->left&&!node->right))
            return cur_depth;
        return std::max(findNext(node->left,cur_depth+1),findNext(node->right,cur_depth+1));
        
    }
};