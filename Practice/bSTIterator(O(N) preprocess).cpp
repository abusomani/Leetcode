/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator
{
private:
    vector<int> V;
    int start;

public:
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            V.push_back(root->val);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode *root)
    {
        inorder(root);
        start = 0;
    }

    /** @return the next smallest number */
    int next()
    {
        return V[start++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return (start < V.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */