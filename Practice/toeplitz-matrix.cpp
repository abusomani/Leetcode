class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        const int N = matrix.size(), M = N ? matrix[0].size() : 0;
        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;

        return true;
    }
};