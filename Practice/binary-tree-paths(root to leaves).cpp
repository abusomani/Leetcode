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
    vector<string> result;

public:
    void dfs(TreeNode *root, string path)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            result.push_back(path + to_string(root->val));
            return;
        }
        dfs(root->left, path + to_string(root->val) + "->");
        dfs(root->right, path + to_string(root->val) + "->");
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return result;
    }
};