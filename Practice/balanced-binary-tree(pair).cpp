/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool res = true;
    // left tree's height, right tree's height
    pair<int,int> dfs(TreeNode *root) {
        if(!root)
            return {0,0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int lh = 1 + max(l.first, l.second), rh = 1 + max(r.first, r.second);
        if(abs(rh-lh) > 1)
            res = false;
        return {lh, rh};
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
};