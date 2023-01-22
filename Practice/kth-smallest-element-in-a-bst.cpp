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
    int ans;

public:
    void inorder(TreeNode *root, int &k)
    {
        if (root)
        {
            inorder(root->left, k);
            if (--k == 0)
            {
                ans = root->val;
                return;
            }
            inorder(root->right, k);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        // inorder(root, k);
        stack<TreeNode *> St;
        while (true)
        {
            while (root != nullptr)
                St.push(root), root = root->left;

            root = St.top();
            St.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
        return ans;
    }
};