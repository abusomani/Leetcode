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
    TreeNode *dfs(vector<int> &inorder, int start, int end, vector<int> &postorder, int &idx)
    {
        if (start > end)
            return nullptr;
        if (idx < 0)
            return nullptr;

        int pos = 0;
        for (int i = start; i <= end; i++)
            if (inorder[i] == postorder[idx])
            {
                pos = i;
                break;
            }

        idx--; // happens only once
        TreeNode *root = new TreeNode(inorder[pos]);
        root->right = dfs(inorder, pos + 1, end, postorder, idx);
        root->left = dfs(inorder, start, pos - 1, postorder, idx);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        const int N = postorder.size();
        assert(inorder.size() == N);
        int idx = N - 1;
        return dfs(inorder, 0, inorder.size() - 1, postorder, idx);
    }
};