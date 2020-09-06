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
class Solution {
private:
    TreeNode * successor(TreeNode *root)
    {
        while(root->left != nullptr)
            root = root->left;
        return root;
    }
    TreeNode * predecessor(TreeNode *root)
    {
        while(root->right != nullptr)
            root = root->right;
        return root;
    }
    void del(TreeNode *& root, int key)
    {
        if(!root)
            return;
        if(root->val > key)
            del(root->left, key);
        else if(root->val < key)
            del(root->right, key);
        else
        {
            if(root->left)
            {
                TreeNode *pre = predecessor(root->left);
                root->val = pre->val;
                del(root->left, pre->val);
            }
            else if(root->right)
            {
                TreeNode *succ = successor(root->right);
                root->val = succ->val;
                del(root->right, succ->val);
            }
            else
                root = nullptr;
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }
};