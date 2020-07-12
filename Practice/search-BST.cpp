//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root)
        {
            if (root->val == val)
                return root;
            else if (root->val > val)
                return searchBST(root->left, val);
            else
                return searchBST(root->right, val);
        }
        return NULL;
    }
};