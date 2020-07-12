class Solution
{
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1) // when size limits are greater than 1, this step can be placed before
            return dp[i][j];

        bool ans = false;
        if (j == p.size())
            ans = (i == s.size()); // both reached end
        else
        {
            bool first_match = (i < s.size() and (p[j] == s[i] or p[j] == '.'));
            if (j + 1 < p.size() and p[j + 1] == '*')
                ans = helper(i, j + 2, s, p, dp)                       // either match to empty string
                      or (first_match and helper(i + 1, j, s, p, dp)); // keep on matching
            else
                ans = first_match and helper(i + 1, j + 1, s, p, dp);
        }

        dp[i][j] = ans;
        return ans;
    }
    bool isMatch(string &s, string &p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(0, 0, s, p, dp);
    }
};