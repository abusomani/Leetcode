class Solution
{
public:
    // int &pre is important else multiple duplicate calls will happen
    TreeNode *dfs(vector<int> &preorder, int &pre, vector<int> &inorder, int start, int end)
    {
        if (pre >= preorder.size())
            return nullptr;
        if (start > end)
            return nullptr;

        int pos = 0;
        for (int i = start; i <= end; i++)
            if (inorder[i] == preorder[pre])
            {
                pos = i;
                break;
            }

        TreeNode *root = new TreeNode(preorder[pre++]);
        root->left = dfs(preorder, pre, inorder, start, pos - 1);
        root->right = dfs(preorder, pre, inorder, pos + 1, end);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int pre = 0;
        return dfs(preorder, pre, inorder, 0, inorder.size() - 1);
    }
};