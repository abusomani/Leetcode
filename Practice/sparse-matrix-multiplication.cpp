class Solution
{
public:
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int N = A.size(), P = N ? A[0].size() : 0, Q = P ? B[0].size() : 0;
        if (N == 0)
            return B;
        if (P == 0)
            return A;

        //C[i][k] = Summation(A[i][j] * B[j][k]);
        vector<vector<int>> res(N, vector<int>(Q, 0));
        for (int row1 = 0; row1 < N; row1++)
        {
            for (int col1 = 0; col1 < P; col1++)
            {
                if (A[row1][col1] != 0)
                {
                    for (int col2 = 0; col2 < Q; col2++)
                    {
                        res[row1][col2] += A[row1][col1] * B[col1][col2];
                    }
                }
            }
        }

        return res;
    }
};