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
    bool isCompleteTree(TreeNode *root)
    {
        TreeNode *node;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty() and (node = Q.front()) != nullptr) // till you encounter first null node
        {
            Q.pop();
            Q.push(node->left);
            Q.push(node->right);
        }

        while (!Q.empty() and Q.front() == nullptr)
            Q.pop(); // pop all nodes

        return Q.empty(); // if there is any non-null nodes, implies its not a complete tree.
    }
};