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
    int ans = 0; // count node in longest path

public:
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left);       // get answer from left side
        int right = dfs(root->right);     // get answer from right side
        ans = max(ans, left + right + 1); // it can be this node is the root, then 1 + left + right ( number of nodes)
        return 1 + max(left, right);      // else 1 + max(l, r) for upwards node
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root);
        return ans - 1; // longest path, count of nodes - 1 is diameter
    }
};