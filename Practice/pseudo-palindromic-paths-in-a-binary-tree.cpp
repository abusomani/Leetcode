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
    int ans = 0;
    bool isPossible(string s)
    {
        int cnt[10] = {0};
        for (auto &i : s)
            cnt[i - '0']++;
        int oddCnt = 0;
        for (int i = 0; i < 10; i++)
            oddCnt += (cnt[i] & 1);

        return oddCnt <= 1;
    }

public:
    void dfs(TreeNode *root, string path)
    {
        if (!root)
            return;
        path += to_string(root->val);
        if (!root->left and !root->right)
        {
            if (isPossible(path))
                ans++;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        string path;
        dfs(root, path);
        return ans;
    }
};