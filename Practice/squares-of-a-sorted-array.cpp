class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> res(A.size());
        // start from both end, fill result array from backwards
        for (int l = 0, r = A.size() - 1, idx = A.size() - 1; l <= r; --idx)
            res[idx] = pow(abs(A[l]) < abs(A[r]) ? A[r--] : A[l++], 2);
        return res;
    }
};