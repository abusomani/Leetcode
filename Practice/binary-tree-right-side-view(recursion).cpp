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
    void preorder(TreeNode *root, int level, vector<int> &result)
    {
        if (!root)
            return;
        if (result.size() < level)
            result.push_back(root->val);
        preorder(root->right, level + 1, result);
        preorder(root->left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        preorder(root, 1, result);
        return result;
    }
};