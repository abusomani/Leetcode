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
    int idx = 0;

public:
    TreeNode *bstFromPreorder(vector<int> &preorder, int lower = INT_MIN, int upper = INT_MAX)
    {
        if (idx == preorder.size())
            return nullptr;
        if (preorder[idx] > upper or preorder[idx] < lower)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorder(preorder, lower, root->val);
        root->right = bstFromPreorder(preorder, root->val, upper);
        return root;
    }
};