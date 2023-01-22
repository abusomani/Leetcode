class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int N = obstacleGrid.size(), M = N ? obstacleGrid[0].size() : 0;
        if (N == 0 or M == 0 or obstacleGrid[0][0])
            return 0;
        vector<vector<int>> dp(N, vector<int>(M, 0));
        //first is based on negation of obstacle
        dp[0][0] = !obstacleGrid[0][0];
        // first row is all 1 until we hit an obstacle
        for (int i = 1; i < N and !obstacleGrid[i][0]; i++)
            dp[i][0] = dp[i - 1][0];
        // first column is all 1 until we hit an obstacle
        for (int i = 1; i < M and !obstacleGrid[0][i]; i++)
            dp[0][i] = dp[0][i - 1];

        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
                if (!obstacleGrid[i][j])
                    dp[i][j] = (obstacleGrid[i - 1][j] == 0 ? dp[i - 1][j] : 0) + (obstacleGrid[i][j - 1] == 0 ? dp[i][j - 1] : 0);

        return dp[N - 1][M - 1];
    }
};