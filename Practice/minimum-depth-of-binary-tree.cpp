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
    int ans = INT_MAX;
public:
    void dfs(TreeNode *root, int depth) {
        if(!root)
            return;
        if(!root->left and !root->right) {
            ans = min(ans, depth);
            return;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root, 1);
        return ans;
    }
};