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
    struct Info
    {
        bool isBst; // is BST or not
        int size;   // size of subtree
        int max;    // max value in subtree
        int min;    // min value in subtree
        int ans;    // largest size of bst subtree
    };

public:
    Info dfs(TreeNode *root)
    {
        if (!root) // is bst
            return {true, 0, INT_MIN, INT_MAX, 0};

        if (!root->left and !root->right) // leaf is always a bst
        {
            return {true, 1, root->val, root->val, 1};
        }

        Info l = dfs(root->left);
        Info r = dfs(root->right);

        int sz = l.size + r.size + 1; // left + right + root
        int mx = max(root->val, max(l.max, r.max));
        int mn = min(root->val, min(l.min, r.min));

        if (l.isBst and r.isBst and (root->val > l.max and root->val < r.min))
        {
            return {true, sz, mx, mn, sz};
        }

        return {false, sz, mx, mn, max(l.ans, r.ans)}; // answer is max from left and right subtree
    }

    int largestBSTSubtree(TreeNode *root)
    {
        return dfs(root).ans;
    }
};