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
int ans = 0;
    void helper(int &ans, int &mn, int &mx, int val, int LorR) {
        ans = max(ans, abs(val - LorR));
        mn = min(mn, LorR); 
        mx = max(mx, LorR);
    }
public:
    pair<int,int> dfs(TreeNode *root) {
        if(!root)
            return {INT_MIN, INT_MIN};
        if(!root->left and !root->right)
            return {root->val, root->val};
        pair<int,int> L = dfs(root->left);
        pair<int,int> R = dfs(root->right);
        int val = root->val, mn = val, mx = val;
        if(L.first != INT_MIN)
            helper(ans, mn, mx, val, L.first);
        if(L.second != INT_MIN)
            helper(ans, mn, mx, val, L.second);
        if(R.first != INT_MIN)
            helper(ans, mn, mx, val, R.first);
        if(R.second != INT_MIN)
            helper(ans, mn, mx, val, R.second);
        return {mn, mx};
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};