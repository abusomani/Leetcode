class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        int N = E.size(), res = 0;
        sort(E.begin(), E.end());
        vector<int> dp(N, 0);
        for(int i=1; i<N; i++){
            for(int j=0; j<i; j++) {
                if(E[i][0]>E[j][0] and E[i][1]>E[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res+1;
    }
};