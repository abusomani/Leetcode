class Solution
{
private:
    map<int, map<int, vector<int>>> vert;

public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        queue<pair<TreeNode *, pair<int, int>>> Q;
        Q.push({root, {0, 0}});

        // left => (X-1, Y+1) and right => (X+1, Y+1)
        while (!Q.empty())
        {
            auto P = Q.front();
            Q.pop();

            vert[P.second.first][P.second.second].push_back(P.first->val);
            if (P.first->left)
                Q.push({P.first->left, {P.second.first - 1, P.second.second + 1}});

            if (P.first->right)
                Q.push({P.first->right, {P.second.first + 1, P.second.second + 1}});
        }

        vector<vector<int>> result;
        for (auto X : vert)
        {
            vector<int> tmp;
            for (auto Y : X.second)
            {
                tmp.insert(tmp.end(), Y.second.begin(), Y.second.end());
            }
            result.push_back(tmp);
        }

        return result;
    }
};