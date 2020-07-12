/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
Input: root = [4,2,5,1,3], target = 3.714286, and k = 2

    4
   / \
  2   5
 / \
1   3

Output: [4,3]
*/
class Solution
{
private:
    deque<int> dq;

public:
    // Kind of sliding window of size K
    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        dq.clear();
        inorder(root, target, k);
        return vector<int>(dq.begin(), dq.end());
    }

    void inorder(TreeNode *root, double target, int k)
    {
        if (!root)
            return;
        inorder(root->left, target, k);
        if (dq.size() >= k)
        {
            if (abs(dq.front() - target) > abs(root->val - target))
                dq.pop_front();
            else
                return;
        }
        dq.push_back(root->val);
        inorder(root->right, target, k);
    }
};