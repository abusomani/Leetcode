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
    vector<int> result;

public:
    void dfs(TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (depth > result.size())
            result.push_back(root->val);
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 1);
        return result;
    }
};