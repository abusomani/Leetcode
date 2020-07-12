class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        stack<TreeNode *> St;
        St.push(root);
        while (!St.empty())
        {
            TreeNode *node = St.top();
            St.pop();

            if (node->right)
                St.push(node->right);
            if (node->left)
                St.push(node->left);

            node->left = NULL;
            node->right = !St.empty() ? St.top() : NULL;
        }
    }
};