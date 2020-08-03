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
    int ans = -1, mx = -1;

public:
    void dfs(TreeNode *root, int level)
    {
        if (!root)
            return;
        if (level > mx)
            ans = root->val, mx = level;

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};