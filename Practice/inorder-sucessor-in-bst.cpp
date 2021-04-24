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
    TreeNode* res = nullptr;
    void dfs(TreeNode *root, TreeNode *p){
        if(root){
            dfs(root->left, p);
            if(root->val > p->val and !res)
                res = root;
            dfs(root->right, p);
        }
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return res;
    }
};