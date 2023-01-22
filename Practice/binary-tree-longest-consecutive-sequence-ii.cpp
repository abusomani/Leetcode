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
    int ans = 0;

public:
    //{incr, decr}
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int incr = 1, decr = 1;
        if (left.first and root->val == root->left->val + 1)
            incr = max(incr, left.first + 1);
        if (left.second and root->val == root->left->val - 1)
            decr = max(decr, left.second + 1);
        if (right.first and root->val == root->right->val + 1)
            incr = max(incr, right.first + 1);
        if (right.second and root->val == root->right->val - 1)
            decr = max(decr, right.second + 1);

        ans = max(ans, incr + decr - 1);
        return {incr, decr};
    }
    int longestConsecutive(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};