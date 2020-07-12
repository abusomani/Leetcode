// Time complexity = O(mn)
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0, ans = 0;
        if (N == 0 or M == 0)
            return 0;
        vector<vector<int>> dp(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (!i or !j or matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }

                ans = max(ans, dp[i][j]);
            }

        return ans * ans;
    }
};