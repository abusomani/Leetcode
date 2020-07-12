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
    struct compare
    {
        bool operator()(pair<double, int> &a, pair<double, int> &b)
        {
            return (a.first < b.first);
        }
    };
    priority_queue<pair<double, int>, vector<pair<double, int>>, compare> PQ;

public:
    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        vector<int> ans;
        inorder(root, target, k);
        while (!PQ.empty())
        {
            ans.push_back(PQ.top().second);
            PQ.pop();
        }
        return ans;
    }

    void inorder(TreeNode *root, double target, int k)
    {
        if (!root)
            return;
        inorder(root->left, target, k);
        PQ.push({abs(target - root->val), root->val});
        if (PQ.size() > k)
            PQ.pop();
        inorder(root->right, target, k);
    }
};