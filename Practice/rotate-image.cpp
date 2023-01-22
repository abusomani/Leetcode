class Solution
{
public:
    void transpose(vector<vector<int>> &matrix, int &N)
    {
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    void swapRows(vector<vector<int>> &matrix, int &N)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N / 2; j++)
                swap(matrix[i][j], matrix[i][N - j - 1]);
    }
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        if (N == 0)
            return;

        transpose(matrix, N);
        swapRows(matrix, N);
    }
};