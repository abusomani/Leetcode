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
struct BSTProps {
    bool isBST;
    long min;
    long max;
};
class Solution {
public:
    BSTProps dfs(TreeNode *root) {
        if(!root)
            return {true, LONG_MAX, LONG_MIN};
        BSTProps left = dfs(root->left);
        BSTProps right = dfs(root->right);
        bool isBst = left.isBST and right.isBST and (left.max < root->val) and (right.min > root->val);
        int mn = min({left.min * 1L, right.min * 1L, root->val* 1L});
        int mx = max({left.max* 1L, right.max* 1L, root->val* 1L});
        return {isBst, mn, mx};
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root).isBST;
    }
};