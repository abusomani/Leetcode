/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Given the root of a binary tree, 
 * find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
 * 
 * 
 Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 */
class Solution
{
private:
    int ans = 0;

public:
    pair<int, int> postOrder(TreeNode *root)
    {
        if (!root)
            return {INT_MAX, INT_MIN};
        if (!root->left and !root->right)
            return {root->val, root->val};
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);
        ans = max(ans,
                  max(
                      abs(root->val - min(left.first, right.first)),
                      abs(root->val - max(left.second, right.second))));
        return {min(root->val, min(left.first, right.first)), max(root->val, max(left.second, right.second))};
    }
    int maxAncestorDiff(TreeNode *root)
    {
        postOrder(root);
        return ans;
    }
};