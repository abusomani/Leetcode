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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root or !p)
            return nullptr;

        TreeNode *succ = nullptr;
        while (root)
        {
            if (root->val > p->val) // this root can be successor, go left
            {
                succ = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return succ;
    }
};