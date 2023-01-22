/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<int, TreeNode *> lca(TreeNode *root, int depth = 1)
    {
        if (!root)
            return {INT_MIN, nullptr};
        if (!root->left and !root->right)
            return {depth, root};
        auto left = lca(root->left, depth + 1);
        auto right = lca(root->right, depth + 1);

        if (left.first > right.first)
            return left;
        else if (right.first > left.first)
            return right;
        else
            return {left.first, root};
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return lca(root).second;
    }
};