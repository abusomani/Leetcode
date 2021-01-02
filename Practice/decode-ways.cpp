class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        vector<int> dp(N, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        for(int i=1; i<N; i++) {
            if(s[i] - '0')
                dp[i] = dp[i-1];
            int val = (s[i-1] - '0')*10 + (s[i] -'0');
            if(val > 9 and val < 27)
                dp[i] += i >= 2 ? dp[i-2] : 1;
        }
        return dp[N-1];
    }
};