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
    bool flipEquiv(TreeNode *A, TreeNode *B)
    {
        if (!A and !B)
            return true;
        if ((!A and B) or (A and !B) or (A->val != B->val))
            return false;

        return (flipEquiv(A->left, B->left) and flipEquiv(A->right, B->right)) or
               (flipEquiv(A->right, B->left) and flipEquiv(A->left, B->right));
    }
};