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
    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s and !t)
            return true;
        if (!s or !t)
            return false;

        return (s->val == t->val and isSame(s->left, t->left) and isSame(s->right, t->right));
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s and !t)
            return true;
        if (!s or !t)
            return false;

        return isSame(s, t) or isSubtree(s->left, t) or isSubtree(s->right, t);
    }
};