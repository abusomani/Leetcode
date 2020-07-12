vector<int> rightSideView(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> Q;
    Q.push(root);
    TreeNode *delim = new TreeNode(INT_MAX);
    Q.push(delim);

    bool toTake = true;
    while (!Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();
        if (toTake)
        {
            result.push_back(node->val);
            toTake = false;
        }
        if (node->val == INT_MAX)
        {
            if (Q.empty())
                break;
            Q.push(delim);
            toTake = true;
            continue;
        }

        if (node->right)
            Q.push(node->right);
        if (node->left)
            Q.push(node->left);
    }
    return result;
}