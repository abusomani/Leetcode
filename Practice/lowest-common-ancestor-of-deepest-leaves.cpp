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
    vector<TreeNode *> leaves;
    int maxDepth = 0;

public:
    TreeNode *lca(TreeNode *root, TreeNode *A, TreeNode *B)
    {
        if (!root or root == A or root == B)
            return root;
        TreeNode *left = lca(root->left, A, B);
        TreeNode *right = lca(root->right, A, B);

        return !left ? right : !right ? left : root;
    }
    void addLeaves(TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                leaves.clear();
            }
            if (depth == maxDepth)
                leaves.push_back(root);
        }
        addLeaves(root->left, depth + 1);
        addLeaves(root->right, depth + 1);
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root)
            return nullptr;

        addLeaves(root, 0);
        TreeNode *ans = leaves[0];
        for (int i = 1; i < leaves.size(); i++)
            ans = lca(root, ans, leaves[i]);

        return ans;
    }
};