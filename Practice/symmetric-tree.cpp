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
    bool isMirror(TreeNode *A, TreeNode *B)
    {
        if (!A or !B)
            return (!A and !B);

        return (A->val == B->val) and isMirror(A->left, B->right) and isMirror(A->right, B->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }
};