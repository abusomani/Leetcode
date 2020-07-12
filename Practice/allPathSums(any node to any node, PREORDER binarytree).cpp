class Solution
{
private:
    vector<vector<int>> result;
    int ans = 0;

public:
    void validate(vector<int> &V, int sum)
    {
        int N = V.size(), sm = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            sm += V[i];
            if (sm == sum)
                ans++;
        }
    }
    void preorder(vector<int> &V, TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;
        V.push_back(root->val);
        preorder(V, root->left, sum);
        preorder(V, root->right, sum);
        validate(V, sum);
        V.pop_back();
    }
    int pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        preorder(path, root, sum);
        return ans;
    }
};