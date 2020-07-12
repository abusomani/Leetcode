class Solution
{
public:
    vector<int> intersection(vector<int> &A, vector<int> &B)
    {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0, N = A.size(), M = B.size();
        vector<int> res;
        while (i < N and j < M)
        {
            if (A[i] == B[j])
            {
                res.push_back(A[i]);
                i++;
                j++;
                while (i < N and A[i] == A[i - 1])
                    i++;
                while (j < M and B[j] == B[j - 1])
                    j++;
            }
            else if (A[i] < B[j])
                i++;
            else
                j++;
        }

        return res;
    }
};