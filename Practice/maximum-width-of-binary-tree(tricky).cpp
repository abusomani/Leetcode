/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recenter by having prev_right, maximum right node seen and subtracting it from the newly computed index
// l = 2*i , r = 2*i + 1, where i starts from =  1
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0, left = 1, right = 1;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 1});
        while (!Q.empty())
        {
            int sz = Q.size();
            ans = max(ans, right - left + 1);
            // recenter every level to avoid overflow of data
            int prev_right = right;
            left = INT_MAX;
            right = INT_MIN;
            while (sz--)
            {
                pair<TreeNode *, int> P = Q.front();
                Q.pop();

                if (P.first->left)
                {
                    int idx = 2 * P.second - prev_right;
                    Q.push({P.first->left, idx});
                    left = min(left, idx);
                    right = max(right, idx);
                }
                if (P.first->right)
                {
                    int idx = 2 * P.second + 1 - prev_right;
                    Q.push({P.first->right, idx});
                    left = min(left, idx);
                    right = max(right, idx);
                }
            }
        }
        return ans;
    }
};