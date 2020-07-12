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
    TreeNode *dfs(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        if (l == r and l < nums.size())
            return new TreeNode(nums[l]);
        int mid = l + ((r - l) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);
    }
};