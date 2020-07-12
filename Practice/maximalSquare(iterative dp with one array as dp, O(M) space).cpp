class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int N = matrix.size(), M = N ? matrix[0].size() : 0, ans = 0, pre = 0;
        if (N == 0 or M == 0)
            return 0;
        vector<int> dp(M, 0); // for columns
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                int temp = dp[j];
                if (!i or !j or matrix[i][j] == '0')
                    dp[j] = matrix[i][j] - '0';
                else
                {
                    dp[j] = min(dp[j - 1], min(dp[j], pre)) + 1;
                }
                pre = temp;
                ans = max(ans, dp[j]);
            }

        return ans * ans;
    }
};