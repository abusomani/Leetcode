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
    TreeNode *successor(TreeNode *root)
    {
        root = root->right;
        while (root->left)
            root = root->left;
        return root;
    }
    TreeNode *predecessor(TreeNode *root)
    {
        root = root->left;
        while (root->right)
            root = root->right;
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int val)
    {
        if (root == nullptr)
            return root;

        if (root->val > val)
            root->left = deleteNode(root->left, val);
        else if (root->val < val)
            root->right = deleteNode(root->right, val);
        else
        {
            if (!root->left and !root->right)
                root = nullptr;
            else if (root->right)
            {
                root->val = successor(root)->val;
                root->right = deleteNode(root->right, root->val);
            }
            else if (root->left)
            {
                root->val = predecessor(root)->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};