class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (N == 0)
            return 0;

        vector<vector<int>> dp(N, vector<int>(3, INT_MAX));
        for (int i = 0; i < 3; i++)
            dp[0][i] = costs[0][i];

        for (int i = 1; i < N; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]; // if ith house is painted with 0th color
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]; // if ith house is painted with 0th color
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2]; // if ith house is painted with 0th color
        }

        return min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    }
};