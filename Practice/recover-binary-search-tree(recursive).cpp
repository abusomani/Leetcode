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
    TreeNode *x = nullptr, *y = nullptr, *prev = nullptr;

public:
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);
        if (prev != nullptr and root->val < prev->val)
        {
            if (x == nullptr)
                x = prev;
            y = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(x->val, y->val);
    }
};