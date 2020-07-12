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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> Q;
        Q.push(root);
        vector<int> tmp;
        while (!Q.empty())
        {
            int sz = Q.size();
            tmp.clear();
            while (sz--)
            {
                TreeNode *node = Q.front();
                Q.pop();
                tmp.push_back(node->val);

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            result.push_back(tmp);
        }

        return result;
    }
};