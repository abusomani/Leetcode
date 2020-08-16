class Solution
{
private:
    vector<vector<vector<int>>> dp;

public:
    // cummulative sum of adjacent
    int brute(vector<int> &P)
    {
        int ans = 0;
        for (int i = 1; i < P.size(); i++)
            if (P[i] > P[i - 1])
                ans += (P[i] - P[i - 1]);

        return ans;
    }
    int dfs(vector<int> &P, int idx, int K, int bought)
    {
        if (idx == P.size() or K < 0)
            return 0;
        if (dp[idx][K][bought] != -1)
            return dp[idx][K][bought];
        int val = dfs(P, idx + 1, K, bought); // no operation here
        if (bought)
            val = max(val, P[idx] + dfs(P, idx, K, false));
        else
            val = max(val, -P[idx] + dfs(P, idx, K - 1, true));
        return dp[idx][K][bought] = val;
    }
    int maxProfit(int K, vector<int> &prices)
    {
        int N = prices.size();
        if (2 * K >= N)
            return brute(prices);
        dp.resize(N, vector<vector<int>>(K + 1, vector<int>(2, -1)));
        return dfs(prices, 0, K, false);
    }
};