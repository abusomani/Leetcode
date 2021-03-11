class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1)
            return n;
        int mx = 1;
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            if(i&1)
                dp[i] += dp[i/2] + dp[i/2 + 1];
            else
                dp[i] = dp[i/2];
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};