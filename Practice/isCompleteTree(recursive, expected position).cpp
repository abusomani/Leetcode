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
    int totalNodes(TreeNode *root)
    {
        return (root != nullptr) ? 1 + totalNodes(root->left) + totalNodes(root->right) : 0;
    }
    bool isComplete(TreeNode *root, int pos, int expectedPos)
    {
        if (!root)
            return true;
        if (pos >= expectedPos)
            return false;
        return isComplete(root->left, 2 * pos + 1, expectedPos) and isComplete(root->right, 2 * pos + 2, expectedPos);
    }
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;
        return isComplete(root, 0, totalNodes(root));
    }
};