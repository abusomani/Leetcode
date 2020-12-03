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
public:
    // <max if including this, max if excluding this>
    pair<int,int> dfs(TreeNode *root) {
        if(!root)
            return {0,0};
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        int rob = root->val + L.second + R.second;
        int notRob = max(L.first, L.second) + max(R.first, R.second);
        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        auto P = dfs(root);
        return max(P.first, P.second);
    }
};