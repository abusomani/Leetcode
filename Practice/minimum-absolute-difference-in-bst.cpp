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
    int diff = INT_MAX;
    TreeNode *prev = nullptr;
    void dfs(TreeNode *root){
        if(root) {
            dfs(root->left);
            if(prev)
                diff = min(diff, root->val - prev->val);
            prev = root;
            dfs(root->right);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return diff;
    }
};