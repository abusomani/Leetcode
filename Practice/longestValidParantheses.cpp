typedef long long ll;
class Solution
{
public:
    //"()(())"
    int longestValidParentheses(string s)
    {
        if (s.size() <= 1)
            return 0;
        ll ans = 0;
        ll N = s.size();
        vector<ll> dp(N, 0);

        for (int i = 1; i < N; i++)
        {
            if (s[i] == ')')
            {

                if (s[i - 1] == '(')
                {
                    dp[i] = (i - 2) >= 0 ? dp[i - 2] + 2 : 2;
                }

                else
                {
                    // check if (i - dp[i-1] - 1) is '(' then its valid
                    if ((i - dp[i - 1] - 1) >= 0 and s[i - dp[i - 1] - 1] == '(')
                    {
                        dp[i] = dp[i - 1] + 2 +
                                ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};