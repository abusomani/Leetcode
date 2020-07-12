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
    TreeNode *compare(TreeNode *root, TreeNode *left, TreeNode *right, TreeNode *p)
    {

        TreeNode *ans = nullptr;
        if (left and left->val > p->val)
            ans = left;
        if (right and right->val > p->val)
        {
            if (!ans or (ans->val > right->val))
                ans = right;
        }
        if (root and root->val > p->val)
        {
            if (!ans or (ans->val > root->val))
                ans = root;
        }
        return ans;
    }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return nullptr;
        TreeNode *left = inorderSuccessor(root->left, p);
        TreeNode *right = inorderSuccessor(root->right, p);
        return compare(root, left, right, p);
    }

    TreeNode *inorderSuccessor1(TreeNode *root, TreeNode *p)
    {
        if (!root or !p)
            return nullptr;

        if (root->val <= p->val) // then definitely in the right
            return inorderSuccessor1(root->right, p);
        else
        {
            TreeNode *succ = inorderSuccessor1(root->left, p); // check in left
            return succ == nullptr ? root : succ;              // if null then root is the successor
        }
    }
};