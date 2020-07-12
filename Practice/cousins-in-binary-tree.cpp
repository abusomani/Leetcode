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
    pair<TreeNode *, int> depthParent(TreeNode *root, TreeNode *parent, int x, int depth)
    {
        if (!root)
            return {nullptr, depth};
        if (root->val == x)
            return {parent, depth};
        auto left = depthParent(root->left, root, x, depth + 1);
        auto right = depthParent(root->right, root, x, depth + 1);
        if (left.first)
            return left;
        if (right.first)
            return right;
        // not present
        return {nullptr, INT_MIN};
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        auto first = depthParent(root, nullptr, x, 0), second = depthParent(root, nullptr, y, 0);
        return (first.first != second.first and first.second == second.second);
    }
};