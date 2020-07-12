class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(dp, 0, 0, m, n);
    }
    int uniquePaths(vector<vector<int>> &dp, int i, int j, int m, int n)
    {
        if (i == m - 1 or j == n - 1)
            return dp[i][j] = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = uniquePaths(dp, i + 1, j, m, n) + uniquePaths(dp, i, j + 1, m, n);
    }
};