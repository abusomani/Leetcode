class Solution
{
public:
    int dfs(int i, int j, int N, int M, vector<vector<char>> &matrix, vector<vector<int>> &dp)
    {
        if (i < 0 or j < 0)
            return 0;
        if (dp[i][j] != 0)
            return dp[i][j];
        if (matrix[i][j] == '0')
            return 0;
        dp[i][j] = min(dfs(i - 1, j - 1, N, M, matrix, dp),
                       min(dfs(i - 1, j, N, M, matrix, dp), dfs(i, j - 1, N, M, matrix, dp))) +
                   1;
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0, ans = 0;
        if (N == 0 or M == 0)
            return 0;
        vector<vector<int>> dp(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans = max(ans, dfs(i, j, N, M, matrix, dp));

        return ans * ans;
    }
};