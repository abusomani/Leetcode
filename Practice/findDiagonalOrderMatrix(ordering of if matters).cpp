class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if (N == 0 or M == 0)
            return result;

        int row = 0, col = 0, d = 1;
        for (int i = 0; i < N * M; i++)
        {
            result.push_back(matrix[row][col]);
            row -= d;
            col += d;

            if (row >= N)
            {
                row = N - 1;
                col += 2;
                d = -d;
            }
            if (col >= M)
            {
                col = M - 1;
                row += 2;
                d = -d;
            }
            if (row < 0)
            {
                row = 0;
                d = -d;
            }
            if (col < 0)
            {
                col = 0;
                d = -d;
            }
        }

        return result;
    }
};