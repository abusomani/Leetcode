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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr and root->right == nullptr)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum - root->val);
    }
};