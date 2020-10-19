class Solution {
private:
    unordered_map<int,unordered_map<int, unordered_map<bool, int>>> dp;
public:
    int dfs(vector<int> &prices, int K, int idx, bool bought) {
        if(K <= 0 or idx == prices.size()) // if K <= 0 or idx >= N you cannot perform any operation, so 0 profit
            return dp[idx][K][bought] = 0;
        if(dp.count(idx) and dp[idx].count(K) and dp[idx][K].count(bought))
            return dp[idx][K][bought];

        int val = dfs(prices, K, idx+1, bought); // do not perform anything
        if(bought) {
            // sell or dont sell
            val = max(prices[idx] + dfs(prices, K-1, idx+1, false), val); // if bought, then you can sell, when you sell, reduce an effective transaction
        }
        else {
            // buy or dont buy
            val = max(-prices[idx] + dfs(prices, K, idx+1, true), val); // if not bought, then you can buy, does not affect the number of transactions
        }
        return dp[idx][K][bought] = val;
    }
    int maxProfitGreedy(vector<int> &prices, int N) {
        int ans = 0, sm = 0;
        for(int i=1; i<N; i++) {
            sm += max(0, prices[i] - prices[i-1]);
            ans = max(ans, sm);
        }
        return ans;
    }
    int maxProfit(int K, vector<int>& prices) {
        int N = prices.size();
        if(N == 0)return 0;
        if(K >= N/2)
            return maxProfitGreedy(prices, N);
        return dfs(prices, K, 0, false);
    }
};