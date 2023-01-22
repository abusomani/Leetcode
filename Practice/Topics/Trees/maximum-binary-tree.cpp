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
    TreeNode *dfs(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mx = INT_MIN, pos = -1;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > mx)
            {
                mx = nums[i];
                pos = i;
            }
        }
        TreeNode *root = new TreeNode(nums[pos]);
        root->left = dfs(nums, l, pos - 1);
        root->right = dfs(nums, pos + 1, r);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int N = nums.size();
        return dfs(nums, 0, N - 1);
    }
};