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
    int ans = INT_MAX;

public:
    void inorder(TreeNode *root, int level)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            ans = min(ans, level);
            return;
        }
        inorder(root->left, level + 1);
        inorder(root->right, level + 1);
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        inorder(root, 1);
        return ans;
    }
};