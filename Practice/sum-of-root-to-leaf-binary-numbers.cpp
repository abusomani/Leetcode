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
class Solution {
private:
    int ans = 0;
    void dfs(TreeNode *root, int val)
    {
        if(!root)
            return;
        if(!root->left and !root->right)
        {
            val = val * 2 + root->val;
            ans += val;
        }
        else
        {
            dfs(root->left, val*2 + root->val);
            dfs(root->right, val*2 + root->val);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};