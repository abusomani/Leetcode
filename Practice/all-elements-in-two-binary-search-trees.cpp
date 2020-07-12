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
    void inorder(TreeNode *A, vector<int> &V)
    {
        if (A)
        {
            inorder(A->left, V);
            V.push_back(A->val);
            inorder(A->right, V);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> A, B, C;
        inorder(root1, A);
        inorder(root2, B);
        int i = 0, j = 0, N = A.size(), M = B.size();
        while (i < N and j < M)
        {
            if (A[i] <= B[j])
                C.push_back(A[i++]);
            else
                C.push_back(B[j++]);
        }

        while (i < N)
            C.push_back(A[i++]);
        while (j < M)
            C.push_back(B[j++]);

        return C;
    }
};