class Solution
{
public:
    int longestValidParentheses(string s)
    {
        const int N = s.size();
        if (N == 0)
            return 0;
        vector<int> dp(N, 0);
        for (int i = 1; i < N; i++)
        {
            // only consider closing braces
            if (s[i] == ')')
            {
                int val = 0;
                // if previous character is opening, then present answer would be either dp[i-2] + 2 or 2, based on index (i-2)>=0
                if (s[i - 1] == '(')
                    val = (i - 2 >= 0) ? dp[i - 2] + 2 : 2;
                // dp[i-1]'s match would be at (i-dp[i-1]), for present character's match, go to (i-dp[i-1]-1) and then story is same
                // tricky thing is if (i - dp[i-1] - 1) matches, we need to add dp[i-dp[i-1]-2], based on index validation check
                else if ((i - dp[i - 1] - 1) >= 0 and s[i - dp[i - 1] - 1] == '(')
                    val = 2 + dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0);

                dp[i] = val;
            }
        }

        //return maximum amongst all
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = max(ans, dp[i]);

        return ans;
    }
};