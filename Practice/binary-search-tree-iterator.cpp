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
class BSTIterator {
private:
    stack<TreeNode*> res;
    void getNext(TreeNode * root) {
        while(root) {
            res.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        getNext(root);
        
    }
    
    int next() {
        if(hasNext()) {
            TreeNode * tp = res.top();
            res.pop();
            getNext(tp->right);
            return tp->val;
        }
        return -1;
    }
    
    bool hasNext() {
        return !res.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */