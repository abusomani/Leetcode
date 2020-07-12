class Solution
{
private:
    vector<vector<int>> result;

public:
    void pathSum(vector<int> &V, TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;
        V.push_back(root->val);
        if (root->left == nullptr and root->right == nullptr and sum == root->val)
        {
            result.push_back(V);
        }
        pathSum(V, root->left, sum - root->val);
        pathSum(V, root->right, sum - root->val);
        V.pop_back(); // backtracking
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> ans;
        pathSum(ans, root, sum);
        return result;
    }
};