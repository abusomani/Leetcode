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
    bool isMirror(TreeNode *a, TreeNode *b) {
        if(!a and !b)return true;
        if(!a or !b)return false;
        return (a->val == b->val and isMirror(a->left, b->right) and isMirror(a->right, b->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};