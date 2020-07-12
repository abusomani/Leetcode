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
    TreeNode *successor(TreeNode *root)
    {
        root = root->right;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    TreeNode *predecessor(TreeNode *root)
    {
        root = root->left;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            // element found
            // leaf then directly make null
            if (root->left == nullptr and root->right == nullptr)
                root = nullptr;
            else if (root->right)
            {
                root->val = successor(root)->val;
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = predecessor(root)->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};