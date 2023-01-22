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
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();
            if (node == nullptr)
                break;
            Q.push(node->left);
            Q.push(node->right);
        }
        while (!Q.empty())
        {
            if (Q.front() != nullptr)
                return false;
            Q.pop();
        }
        return true;
    }
};