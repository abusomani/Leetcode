class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        N = matrix.size();
        M = N ? matrix[0].size() : 0;
        prefixSum.resize(matrix.size());
        for (int i = 0; i < N; i++)
        {
            vector<int> row(M, 0);
            row[0] = matrix[i][0];
            for (int j = 1; j < M; j++)
                row[j] = row[j - 1] + matrix[i][j];

            prefixSum[i] = row;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int minCol = min(col1, col2), maxCol = max(col1, col2);
        int ans = 0;
        for (int i = row1; i <= row2; i++)
            ans += prefixSum[i][maxCol] - (minCol > 0 ? prefixSum[i][minCol - 1] : 0);

        return ans;
    }

private:
    int N, M;
    vector<vector<int>> prefixSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */