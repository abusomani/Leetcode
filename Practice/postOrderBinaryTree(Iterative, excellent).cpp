class Solution
{
private:
    enum
    {
        ENTER,
        EXIT
    };

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<pair<int, TreeNode *>> St;
        St.push({ENTER, root});

        while (!St.empty())
        {
            pair<int, TreeNode *> P = St.top();
            St.pop();

            if (P.second == nullptr)
                continue;

            if (P.first == EXIT)
            {
                ans.push_back(P.second->val);
            }
            else
            {
                St.push({EXIT, P.second});
                if (P.second->right)
                    St.push({ENTER, P.second->right});
                if (P.second->left)
                    St.push({ENTER, P.second->left});
            }
        }

        return ans;
    }
};