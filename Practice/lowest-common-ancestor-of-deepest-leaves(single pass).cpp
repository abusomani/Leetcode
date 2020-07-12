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
    pair<TreeNode *, int> lca(TreeNode *root)
    {
        if (root == nullptr)
            return {nullptr, 0};
        auto left = lca(root->left);
        auto right = lca(root->right);
        if (left.second > right.second) // left has a higher depth
            return {left.first, left.second + 1};
        else if (left.second < right.second)
            return {right.first, right.second + 1};
        return {root, max(left.second, right.second) + 1};
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return lca(root).first;
    }
};