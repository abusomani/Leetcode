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
    unordered_set<int> St;

public:
    bool dfs(TreeNode *root, int k)
    {
        if (!root)
            return false;
        bool possible = dfs(root->left, k);
        if (possible)
            return true;
        if (St.count(k - root->val))
            return true;
        St.insert(root->val);
        return possible or dfs(root->right, k);
    }
    bool findTarget(TreeNode *root, int k)
    {
        return dfs(root, k);
    }
};