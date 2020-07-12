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
    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mx = -1, idx = -1;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > mx)
            {
                mx = nums[i];
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(mx);
        root->left = helper(nums, l, idx - 1);
        root->right = helper(nums, idx + 1, r);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        return helper(nums, 0, nums.size() - 1);
    }
};