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
    long dfs(TreeNode *root, int smallest){
        if(!root)
            return LONG_MAX;
        if(root->val != smallest)
            return root->val;
        auto l = dfs(root->left, smallest);
        auto r = dfs(root->right, smallest);
        return min(l, r);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int smallest = root->val;
        long ans = dfs(root, smallest);
        return ans == LONG_MAX ? -1 : (int)ans;
    }
};