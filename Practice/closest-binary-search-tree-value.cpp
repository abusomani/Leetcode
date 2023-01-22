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
    double diff = LONG_MAX;

public:
    void dfs(TreeNode *root, double target)
    {
        if (!root)
            return;
        dfs(root->left, target);
        if (abs(target - root->val) < diff)
        {
            diff = abs(target - root->val);
            ans = root->val;
        }
        dfs(root->right, target);
    }
    int closestValue(TreeNode *root, double target)
    {
        dfs(root, target);
        return ans;
    }
};