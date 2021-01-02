/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    string path;
public:
    void dfs(TreeNode *root, TreeNode *target, string p) {
        if(!root)return;
        if(root == target)
            path = p;
        dfs(root->left, target, p + 'L');
        dfs(root->right, target, p + 'R');
    }
    TreeNode* clonedNode(TreeNode *root, string P, int idx) {
        if(idx == P.size())
            return root;
        if(P[idx] == 'L')
            return clonedNode(root->left, P, idx+1);
        return clonedNode(root->right, P, idx+1);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, target, "");
        return clonedNode(cloned, path, 0);
    }
};