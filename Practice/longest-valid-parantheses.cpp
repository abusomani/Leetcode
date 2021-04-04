class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size(), res = 0;
        vector<int> dp(N, 0);
        for(int i=1; i<N; i++){
            if(s[i] == ')')
            {
                // 2 + longest valid till i-2
                if(s[i-1] == '(')
                    dp[i] += (i >= 2 ? 2 + dp[i-2] : 2);
                else if(s[i-1] == ')')
                {
                    // i - dp[i-1] - 1 is opening bracket then its 2 + dp[i-1] + longest till (i - dp[i-1] - 2)
                    if(i - dp[i-1] - 1 >= 0 and s[i-dp[i-1]-1] == '(')
                        dp[i] += 2 + dp[i-1] + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};