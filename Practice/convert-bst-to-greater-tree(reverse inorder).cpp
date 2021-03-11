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
private:
    int sm = 0;
    void reverseInorder(TreeNode *root)
    {
        if (!root)
            return;
        reverseInorder(root->right);
        sm += root->val;
        root->val = sm;
        reverseInorder(root->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        reverseInorder(root);
        return root;
    }
};