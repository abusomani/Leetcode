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
    int maxDepth = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxDepth;
    }
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        maxDepth = max(maxDepth, left + right);

        return 1 + max(left, right);
    }
};