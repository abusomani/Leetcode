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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        } 
        
        d--;
        int level = 1;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--){
                TreeNode *curr = Q.front(); Q.pop();
                if(!curr)continue;

                if(level == d) {
                    TreeNode *l = new TreeNode(v);
                    l->left = curr->left;
                    Q.push(curr->left);
                    TreeNode *r = new TreeNode(v);
                    r->right = curr->right;
                    Q.push(curr->right);
                    curr->left = l;
                    curr->right = r;
                    continue;
                }
                Q.push(curr->left);
                Q.push(curr->right);
            }
            level++;
            if(level > d)
                return root;
        }
        return root;
    }
};