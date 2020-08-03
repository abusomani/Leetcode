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
class Solution
{
private:
    vector<int> leafA, leafB;

public:
    void addLeaves(TreeNode *A, vector<int> &V)
    {
        if (!A)
            return;
        if (!A->left and !A->right)
            V.push_back(A->val);
        addLeaves(A->left, V);
        addLeaves(A->right, V);
    }
    bool leafSimilar(TreeNode *A, TreeNode *B)
    {
        addLeaves(A, leafA);
        addLeaves(B, leafB);
        return leafA == leafB;
    }
};