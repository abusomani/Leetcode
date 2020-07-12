/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int ans = 0;

public:
    int dfs(TreeNode *root, int val)
    {
        if (!root)
            return 0;
        int l = dfs(root->left, root->val);
        int r = dfs(root->right, root->val);
        ans = max(ans, l + r);
        if (root->val == val) // if value is same as what is expected, return 1 + max(l,r) for tree above it
            return 1 + max(l, r);
        return 0; // if child node's value is different from what is expected, return 0
    }
    int longestUnivaluePath(TreeNode *root)
    {
        if (!root)
            return 0;

        dfs(root, root->val);
        return ans;
    }
};