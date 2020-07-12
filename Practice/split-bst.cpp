/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * if value of root <= target, we split subtree rooted at root.right -> subproblem
 * else (value of root > target), we split subtree rooted at root.left -> subproblem
 * 
 * Nodes of the subtree rooted at result[0] <= target
 * Nodes of the subtree rooted at result[1] > target
 */
class Solution
{
public:
    vector<TreeNode *> splitBST(TreeNode *root, int V)
    {
        if (!root)
            return {NULL, NULL};
        vector<TreeNode *> trees;
        if (root->val <= V)
        {
            trees = splitBST(root->right, V);
            root->right = trees[0];
            trees[0] = root;
        }
        else
        {
            trees = splitBST(root->left, V);
            root->left = trees[1];
            trees[1] = root;
        }
        return trees;
    }
};