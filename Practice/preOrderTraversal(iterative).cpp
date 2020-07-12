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
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> St;
        vector<int> result;
        if (!root)
            return result;
        St.push(root);
        while (!St.empty())
        {
            TreeNode *curr = St.top();
            St.pop();
            result.push_back(curr->val);
            if (curr->right)
                St.push(curr->right);
            if (curr->left)
                St.push(curr->left);
        }

        return result;
    }
};