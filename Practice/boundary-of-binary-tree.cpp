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
    vector<int> nodes;

public:
    // dont add leaves here
    // PREORDER style as it is in direction of traversal
    void leftBoundary(TreeNode *root)
    {
        if (!root or (!root->left and !root->right))
            return;
        nodes.push_back(root->val);
        if (!root->left)
            leftBoundary(root->right);
        else
            leftBoundary(root->left);
    }
    // dont add leaves here
    // POSTORDER style as it is in reverse direction
    void rightBoundary(TreeNode *root)
    {
        if (!root or (!root->left and !root->right))
            return;
        if (!root->right)
            rightBoundary(root->left);
        else
            rightBoundary(root->right);
        nodes.push_back(root->val);
    }
    void addLeafNodes(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            nodes.push_back(root->val);
            return;
        }
        addLeafNodes(root->left);
        addLeafNodes(root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        nodes.clear();
        if (!root)
            return nodes;
        nodes.push_back(root->val);
        leftBoundary(root->left);
        addLeafNodes(root->left);
        addLeafNodes(root->right);
        rightBoundary(root->right);
        return nodes;
    }
};