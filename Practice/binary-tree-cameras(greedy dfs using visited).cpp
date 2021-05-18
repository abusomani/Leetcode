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
public:
    int res = 0;
    unordered_set<TreeNode*> St;
    void visit(TreeNode *node, TreeNode *p){
        St.insert(node); St.insert(node->left); St.insert(node->right); St.insert(p);
    }
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node) 
        {
            dfs(node->left, node);
            dfs(node->right, node);

            if (!parent and !St.count(node) or !St.count(node->left) or !St.count(node->right)) {
                res++;
                visit(node, parent);
            }
        }
    }
    int minCameraCover(TreeNode* root)
    {
        St.insert(nullptr);
        dfs(root, nullptr);
        return res;
    }
};