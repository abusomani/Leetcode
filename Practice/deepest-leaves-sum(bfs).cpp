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
    int deepestLeavesSum(TreeNode *root)
    {
        int res = 0;
        if (!root)
            return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int N = Q.size();
            res = 0;
            while (N--)
            {
                TreeNode *node = Q.front();
                Q.pop();
                res += node->val;
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
        }
        return res;
    }
};