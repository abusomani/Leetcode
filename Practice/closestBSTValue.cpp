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
    double diff = DBL_MAX; // needed across recursion calls for comparison.

public:
    int closestValue(TreeNode *root, double target)
    {
        int ans = root->val;
        inorder(root, target, ans);
        return ans;
    }

    void inorder(TreeNode *root, double target, int &ans)
    {
        if (!root)
            return;
        inorder(root->left, target, ans);
        if (abs(root->val - target) < diff)
        {
            diff = abs(root->val - target);
            ans = root->val;
        }
        inorder(root->right, target, ans);
    }
};