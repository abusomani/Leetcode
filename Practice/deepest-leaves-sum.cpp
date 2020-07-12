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
    int depth = 0, ans = 0;

public:
    void dfs(TreeNode *root, int d)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            if (d >= depth)
            {
                ans = (d > depth) ? root->val : ans + root->val; // if a new deeper leaf, then answer becomes this, else add to existing ans
                depth = max(d, depth);
            }
            return;
        }
        else
        {
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        }
    }
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};