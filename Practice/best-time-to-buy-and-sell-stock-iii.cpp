class Solution
{
private:
    vector<vector<vector<int>>> dp;

public:
    int dfs(vector<int> &P, int idx, int K, bool bought)
    {
        if (idx == P.size() or K < 0)
            return 0;
        if (dp[idx][K][bought] != -1)
            return dp[idx][K][bought];
        int val = dfs(P, idx + 1, K, bought);
        if (bought)
            val = max(P[idx] + dfs(P, idx + 1, K, false), val);
        else
            val = max(-P[idx] + dfs(P, idx + 1, K - 1, true), val);
        return dp[idx][K][bought] = val;
    }
    int maxProfit(vector<int> &prices)
    {
        int N = prices.size();
        dp.resize(N, vector<vector<int>>(3, vector<int>(2, -1)));
        return dfs(prices, 0, 2, false);
    }
};