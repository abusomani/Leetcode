/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *dfs(vector<int> &preorder, int &id, int limit)
    {
        if (id == (int)preorder.size() or preorder[id] > limit)
            return nullptr;
        int num = preorder[id];
        TreeNode *root = new TreeNode(num);
        id++;
        root->left = dfs(preorder, id, num);
        root->right = dfs(preorder, id, limit);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return nullptr;

        int id = 0;
        return dfs(preorder, id, INT_MAX);
    }
};