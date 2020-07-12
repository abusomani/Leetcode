class Solution
{
public:
    // KMP to calculate failure function
    vector<int> KMP(string s)
    {
        int N = s.size(), j = 0;
        vector<int> dp(N, 0);
        for (int i = 1; i < N; i++)
        {
            j = dp[i - 1]; // always start from previous character's match position
            while (j and s[i] != s[j])
                j = dp[j - 1];                      // go back to last seen positions based on memoization
            dp[i] = (s[i] == s[j]) ? j + 1 : dp[i]; // if match then for subsequent character start matching from (j+1)th position as previous j match.
        }

        return dp;
    }
    bool repeatedSubstringPattern(string s)
    {
        vector<int> F = KMP(s);
        int N = s.size(), last = F.back(), pattern_size = N - last;
        // size of pattern is (N-n)
        return (last and last % pattern_size == 0);
    }
};