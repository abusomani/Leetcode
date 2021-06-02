class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<vector<int>> dp(N, vector<int>(3, INT_MAX));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i=1; i<N; i++){
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][1], dp[i-1][0]);
        }
        return min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    }
};