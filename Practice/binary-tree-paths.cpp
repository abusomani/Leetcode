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
public:
    vector<string> result;
    string nextResult(string res, int val)
    {
        // empty check is required else, for single root answer would be "->1"
        return res.empty() ? to_string(val) : res + "->" + to_string(val);
    }
    void dfs(TreeNode *root, string res)
    {
        if (!root)
            return;
        string next = nextResult(res, root->val);
        if (!root->left and !root->right)
        {
            result.push_back(next);
            return;
        }
        dfs(root->left, next);
        dfs(root->right, next);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return result;
    }
};