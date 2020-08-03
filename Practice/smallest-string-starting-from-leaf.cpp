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
    set<string> St;

public:
    void dfs(TreeNode *root, string path)
    {
        if (!root)
            return;
        path += string(1, root->val + 'a');
        if (!root->left and !root->right)
        {
            reverse(path.begin(), path.end());
            St.insert(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string path = "";
        dfs(root, path);
        return *St.begin();
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
class Solution1
{
    // No need of maintaing set, only one answer is enough
private:
    string answer = "$";

public:
    void dfs(TreeNode *root, string path)
    {
        if (!root)
            return;
        path += string(1, root->val + 'a');
        if (!root->left and !root->right)
        {
            reverse(path.begin(), path.end());
            if (answer == "$")
                answer = path;
            else
                answer = min(answer, path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string path = "";
        dfs(root, path);
        return answer;
    }
};