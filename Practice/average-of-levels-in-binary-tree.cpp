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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        if (!root)
            return res;

        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int sz = Q.size(), cnt = sz;
            double sum = 0;
            while (sz--)
            {
                TreeNode *node = Q.front();
                Q.pop();
                sum += node->val;

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            res.push_back(sum / cnt);
        }

        return res;
    }
};