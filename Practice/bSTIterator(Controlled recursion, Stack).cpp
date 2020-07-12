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
    stack<TreeNode *> St;

public:
    void pushNodes(TreeNode *root)
    {
        while (root)
        {
            St.push(root);
            root = root->left;
        }
    }

    void controlledInorder(TreeNode *root)
    {
        pushNodes(root);
    }

    BSTIterator(TreeNode *root)
    {
        controlledInorder(root);
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *nxt = St.top();
        int val = St.top()->val;
        St.pop();
        pushNodes(nxt->right);

        return val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return St.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */