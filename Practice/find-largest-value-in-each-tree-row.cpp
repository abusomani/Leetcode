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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        TreeNode *node;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int sz = Q.size(), ans = INT_MIN;
            while (sz--)
            {
                node = Q.front();
                ans = max(ans, node->val);
                Q.pop();
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            res.push_back(ans);
        }

        return res;
    }
};