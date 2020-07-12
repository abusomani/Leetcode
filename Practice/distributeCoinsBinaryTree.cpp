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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traverse(root,moves);
        return moves;
    }
    int traverse(TreeNode * root, int &moves){
        if(!root)return 0;
        int l = traverse(root->left,moves);
        int r = traverse(root->right,moves);
        moves += abs(l) + abs(r);
        
        return (root->val + l + r - 1);// coins returned back.
    }
};