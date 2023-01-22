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
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        map<int, map<int, vector<int>>> Mp;
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<pair<TreeNode *, pair<int, int>>> Q;
        Q.push({root, {0, 0}});
        while (!Q.empty())
        {
            auto P = Q.front();
            Q.pop();
            TreeNode *node = P.first;
            int x = P.second.first, y = P.second.second;
            Mp[x][y].push_back(node->val);
            if (node->left)
                Q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                Q.push({node->right, {x + 1, y + 1}});
        }

        for (auto &x : Mp)
        {
            vector<int> tmp;
            for (auto &y : x.second)
                for (auto &i : y.second)
                    tmp.push_back(i);

            res.push_back(tmp);
        }
        return res;
    }
};