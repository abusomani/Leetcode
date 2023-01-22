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
    bool hasPathSum(TreeNode *root, int sum, int curr = 0)
    {
        if (!root)
            return false;
        if (!root->left and !root->right)
            return sum == curr + root->val;

        return hasPathSum(root->left, sum, root->val + curr) or hasPathSum(root->right, sum, root->val + curr);
    }
};