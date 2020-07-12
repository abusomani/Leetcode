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
    int longestConsecutive(const TreeNode *node, int parval = -1, int len = 0)
    {
        if (node == nullptr)
            return 0;
        len = (parval == (node->val - 1)) ? (len + 1) : 1;
        return max(max(longestConsecutive(node->left, node->val, len), longestConsecutive(node->right, node->val, len)), len);
    }
};