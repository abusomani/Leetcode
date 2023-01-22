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
    bool dfs(TreeNode *root)
    {
        if (!root)
            return true;

        auto isleftValid = dfs(root->left);
        auto isRightValid = dfs(root->right);

        if (isleftValid and isRightValid and
            (!root->left or (root->left->val == root->val)) and (!root->right or (root->right->val == root->val)))
        {
            ans++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};