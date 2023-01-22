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
private:
    deque<int> Dq;

public:
    void dfs(TreeNode *root, double &target, int &k)
    {
        if (!root)
            return;
        dfs(root->left, target, k);
        // if dq size is already >= K
        if (Dq.size() >= k)
        {
            if (abs(target - Dq.front()) > abs(target - root->val))
                Dq.pop_front();
            // adding this value will just increate the difference, so better return
            else
                return;
        }
        Dq.push_back(root->val);
        dfs(root->right, target, k);
    }
    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        dfs(root, target, k);
        vector<int> V;
        for (auto &id : Dq)
            V.push_back(id);
        return V;
    }
};