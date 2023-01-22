class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> result;
        const int N = A.size(), M = B.size();
        if (N == 0 or M == 0)
            return result;
        int i = 0, j = 0;
        while (i < N and j < M)
        {
            if (A[i][1] < B[j][0])
                i++;
            else if (A[i][0] > B[j][1])
                j++;
            else
            {
                int start = max(A[i][0], B[j][0]), end = min(A[i][1], B[j][1]);
                result.push_back({start, end});
                if (A[i][1] > B[j][1])
                    j++;
                else
                    i++;
            }
        }
        return result;
    }
};