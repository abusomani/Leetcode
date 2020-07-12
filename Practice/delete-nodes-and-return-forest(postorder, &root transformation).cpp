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
private:
    vector<TreeNode *> result;
    unordered_set<int> toDelete;

public:
    void dfs(TreeNode *&root) // *& for changing the root itself
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);

        if (toDelete.find(root->val) != toDelete.end()) // if this has to be deleted, then both child become forests
        {
            if (root->left)
                result.push_back(root->left);
            if (root->right)
                result.push_back(root->right);
            root = nullptr;
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        for (auto i : to_delete)
            toDelete.insert(i);
        dfs(root);
        if (root) // if root was not deleted then add that as well
            result.push_back(root);
        return result;
    }
};