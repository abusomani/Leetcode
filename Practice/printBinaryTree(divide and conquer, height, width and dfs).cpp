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
    int height(TreeNode *root)
    {
        return (root == NULL) ? 0 : 1 + max(height(root->left), height(root->right));
    }
    // at every step return 2*max(left,right) + 1
    int width(TreeNode *root)
    {
        return (root == NULL) ? 0 : 2 * max(width(root->left), width(root->right)) + 1;
    }
    vector<vector<string>> printTree(TreeNode *root)
    {
        int rows = height(root);
        int cols = width(root);
        vector<vector<string>> result(rows, vector<string>(cols, ""));
        helper(root, result, 0, 0, cols - 1);
        return result;
    }
    // divide and conquer
    void helper(TreeNode *root, vector<vector<string>> &result, int level, int l, int r)
    {
        if (!root)
            return;
        int mid = (l + r) / 2;
        result[level][mid] = to_string(root->val);
        helper(root->left, result, level + 1, l, mid - 1);
        helper(root->right, result, level + 1, mid + 1, r);
    }
};