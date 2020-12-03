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
    vector<TreeNode *> path;

public:
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            path.push_back(root);
            inorder(root->right);
        }
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        inorder(root);
        TreeNode dummy(0);
        TreeNode *pre = &dummy;
        for (auto node : path)
            pre->right = node, node->left = nullptr, node->right = nullptr, pre = pre->right;
        return dummy.right;
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
private:
    TreeNode *first = nullptr, *prev = nullptr;

public:
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            if (!first)
                first = root, prev = root;
            else if (prev)
                prev->left = nullptr, prev->right = root, prev = prev->right;
            inorder(root->right);
        }
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        inorder(root);
        return first;
    }
};