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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        max_gain(root);
        return max_sum;
    }
    int max_gain(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = max(max_gain(root->left), 0);
        int r = max(max_gain(root->right), 0);

        max_sum = max(max_sum, l + r + root->val);

        // still go up
        return root->val + max(l, r);
    }
};