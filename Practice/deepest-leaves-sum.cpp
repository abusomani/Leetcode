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
    int depth = 0, ans = 0;

public:
    void dfs(TreeNode *root, int d)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            if (d >= depth)
            {
                ans = (d > depth) ? root->val : ans + root->val; // if a new deeper leaf, then answer becomes this, else add to existing ans
                depth = max(d, depth);
            }
            return;
        }
        else
        {
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        }
    }
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};

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
private:
    int mx = 0;
    unordered_map<int, int> Mp;
    void dfs(TreeNode *root, int depth = 0)
    {
        if (root)
        {
            if (!root->left and !root->right)
                Mp[depth] += root->val, mx = max(mx, depth);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root);
        return Mp[mx];
    }
};