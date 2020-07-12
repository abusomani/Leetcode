class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int N = mat.size(), M = N ? mat[0].size() : 0;
        if (N == 0 or M == 0)
            return mat;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> Mp;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                Mp[i - j].push(mat[i][j]);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                mat[i][j] = Mp[(i - j)].top();
                Mp[(i - j)].pop();
            }

        return mat;
    }
};