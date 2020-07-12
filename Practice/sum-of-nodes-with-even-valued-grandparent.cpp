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
    int ans = 0;

public:
    void preorder(TreeNode *root, pair<int, int> parentPair)
    {
        if (!root)
            return;

        ans += (parentPair.second & 1) ? 0 : root->val;
        preorder(root->left, {root->val, parentPair.first});
        preorder(root->right, {root->val, parentPair.first});
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        if (!root)
            return 0;
        preorder(root, {-1, -1});
        return ans;
    }
    int sumEvenGrandparent1(TreeNode *root, int p = -1, int gp = -1)
    {
        return root ? sumEvenGrandparent1(root->left, root->val, p) + sumEvenGrandparent1(root->right, root->val, p) + ((gp & 1) ? 0 : root->val) : 0;
    }
};