// KMP can be used to find longest palindrome prefix starting at index 0
// By this way, whatever part remains, has to be reverse added in front of string.
// For doing KMP and finding LPP, you need to send ( s +  '#' + reverse(s))
// This will return the longest prefix which is also a suffix and that is what we need
class Solution
{
public:
    vector<int> KMP(string s)
    {
        int N = s.size(), j = 0;
        vector<int> dp(N, 0);
        for (int i = 1; i < N; i++)
        {
            j = dp[i - 1];
            while (j > 0 and s[j] != s[i])
                j = dp[j - 1];
            if (s[i] == s[j])
                j++;
            dp[i] = j;
        }
        return dp;
    }
    string shortestPalindrome(string s)
    {
        if (s.empty() or s.size() == 1)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<int> LCP = KMP(s + "$" + rev);
        string endPart = s.substr(LCP.back());
        reverse(endPart.begin(), endPart.end());
        return endPart + s;
    }
};