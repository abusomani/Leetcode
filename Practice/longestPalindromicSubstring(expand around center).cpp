class Solution
{
private:
    int low, maxLen = 0;

public:
    void expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 and R < s.size() and s[L] == s[R])
            L--, R++;
        if (R - L - 1 > maxLen)
        {
            maxLen = R - L - 1; // (R -1 + L + 1 - 1)
            low = L + 1;        // as it must have been decremented in earlier loop
        }
    }
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        for (int i = 0; i < s.size() - 1; i++)
        {
            expandAroundCenter(s, i, i);     //assume odd length, try to extend Palindrome as possible
            expandAroundCenter(s, i, i + 1); //assume even length.
        }

        return s.substr(low, maxLen);
    }
};