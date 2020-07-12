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
    void dfs(TreeNode *root, int curr)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            curr = curr * 10 + root->val;
            ans += curr;
            return;
        }
        dfs(root->left, curr * 10 + root->val);
        dfs(root->right, curr * 10 + root->val);
    }
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};