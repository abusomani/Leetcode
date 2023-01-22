/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 T(n) = T(n/2) + c1 lgn
       = T(n/4) + c1 lgn + c2 (lgn - 1)
       = ...
       = T(1) + c [lgn + (lgn-1) + (lgn-2) + ... + 1]
       = O(lgn*lgn)   
 */
class Solution
{
public:
    // Time Complexity => O(logN * logN)
    /*
        At first I thought it spends O(NlogN), too. 
        But actually only one recursive call in countNodes(root->left)+countNodes(root->right) will be really recursively called.
        Think about the bottom level of a complete tree, which can be separated into two pieces at the mid.
        The trick is, there must be one half, which is still a complete tree. You can draw and try.
        So, there are logN levels, every level needs logN time, the whole time complexity is O(logN * logN).
    */
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int hl = 0, hr = 0;
        TreeNode *l = root, *r = root;
        while (l)
        {
            hl++;
            l = l->left;
        }
        while (r)
        {
            hr++;
            r = r->right;
        }

        if (hl == hr)               // complete binary tree
            return ((1 << hl) - 1); // skips almost half tree

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Time Complexity => O(N)
    int countNodes1(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};