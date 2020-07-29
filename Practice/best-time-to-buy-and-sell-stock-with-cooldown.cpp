class Solution
{
private:
    vector<vector<int>> dp;

public:
    int dfs(vector<int> &prices, int idx, bool bought)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][bought] != -1)
            return dp[idx][bought];
        int val = 0;
        if (bought)
        {
            // can sell today or cannot sell today
            val = max(
                prices[idx] + dfs(prices, idx + 2, false),
                dfs(prices, idx + 1, true));
        }
        else
        {
            // max of (buying today or not buying today)
            val = max(
                -prices[idx] + dfs(prices, idx + 1, true),
                dfs(prices, idx + 1, false));
        }
        return dp[idx][bought] = val;
    }
    int maxProfit(vector<int> &prices)
    {
        int N = prices.size();
        dp.resize(N, vector<int>(2, -1));
        return dfs(prices, 0, false);
    }
};