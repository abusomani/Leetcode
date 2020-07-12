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
    // if depth of one side of root is 0 , take other side
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (min(L, R) > 0 ? min(L, R) : max(L, R));
    }
};