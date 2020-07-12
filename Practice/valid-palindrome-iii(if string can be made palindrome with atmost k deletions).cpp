class Solution
{
public:
    int dp[1000][1000] = {};
    int dfs(string &s, int l, int r) // string &s will cause AC and string s will cause TLE
    {
        if (l >= r)
            return 1;
        if (!dp[l][r])
        {
            if (s[l] == s[r])
                return dp[l][r] = dfs(s, l + 1, r - 1);
            else
                return dp[l][r] = 1 + min(dfs(s, l + 1, r), dfs(s, l, r - 1));
        }
        return dp[l][r];
    }
    bool isValidPalindrome(string s, int k)
    {
        return dfs(s, 0, s.size() - 1) - 1 <= k;
    }
};