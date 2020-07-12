/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    https://assets.leetcode.com/uploads/2019/05/02/tree.png
 */
class Solution
{
private:
    int prev = 0;

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root)
        {
            bstToGst(root->right);
            root->val += prev;
            prev = root->val;
            bstToGst(root->left);
        }
        return root;
    }
};