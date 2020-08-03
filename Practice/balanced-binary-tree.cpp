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
class Solution
{
public:
    int dfs(TreeNode *root, bool &isValid)
    {
        if (!root)
            return 0;
        if (!root->left and !root->right)
            return 1;
        int l = dfs(root->left, isValid);
        int r = dfs(root->right, isValid);
        if (abs(l - r) > 1)
            isValid = false;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode *root)
    {
        bool isValid = true;
        dfs(root, isValid);
        return isValid;
    }
};