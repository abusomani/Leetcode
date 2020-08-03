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
private:
    int count = 0;

public:
    void dfs(TreeNode *root, int mx_till_here)
    {
        if (!root)
            return;
        if (root->val >= mx_till_here)
            count++;
        mx_till_here = max(mx_till_here, root->val);
        dfs(root->left, mx_till_here);
        dfs(root->right, mx_till_here);
    }
    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, INT_MIN);
        return count;
    }
};