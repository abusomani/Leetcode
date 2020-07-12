class Solution
{
private:
    map<int, map<int, set<int>>> vert;

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        inorder(root, 0, 0);
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

    void inorder(TreeNode *root, int x, int y)
    {
        if (!root)
            return;
        vert[x][y].insert(root->val);
        inorder(root->left, x - 1, y + 1);
        inorder(root->right, x + 1, y + 1);
    }
};