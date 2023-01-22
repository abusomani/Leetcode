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
class Solution
{
public:
    bool dfs(TreeNode *root, vector<int> &arr, int idx, int N)
    {
        if (!root)
            return false;
        if (idx == N - 1) // last index
            return (root and root->val == arr[idx] and !root->left and !root->right);

        return root->val == arr[idx] and (dfs(root->left, arr, idx + 1, N) or dfs(root->right, arr, idx + 1, N));
    }
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return dfs(root, arr, 0, arr.size());
    }
};