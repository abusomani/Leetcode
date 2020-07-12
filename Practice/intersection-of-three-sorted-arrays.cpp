class Solution
{
public:
    vector<int> arraysIntersection(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while (i < A.size() and j < B.size() and k < C.size())
        {
            int mx = max({A[i], B[j], C[k]});
            if (A[i] == B[j] and B[j] == C[k])
            {
                res.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else
            {
                if (A[i] < mx)
                    i++;
                if (B[j] < mx)
                    j++;
                if (C[k] < mx)
                    k++;
            }
        }

        return res;
    }
};