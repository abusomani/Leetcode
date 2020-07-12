class Solution
{
public:
    int numDecodings(string s)
    {
        //224206
        //12
        int N = s.size();
        if (N == 0 or s[0] == '0')
            return 0;
        if (N == 1)
            return 1; // one number always 1

        int dp[N];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i < N; i++)
        {
            if (s[i] - '0')
            { // if not zero then number of strings till ith is same as (i-1)th
                dp[i] = dp[i - 1];
            }
            int value = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (value > 9 and value <= 26) // add all ways till dp(i-2), else 1 way e.g : 226
                dp[i] += (i - 2) >= 0 ? dp[i - 2] : 1;
        }

        return dp[N - 1];
    }
};