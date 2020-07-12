class Solution
{
public:
    int expandAroundCenter(int left, int right, string &s)
    {
        int L = left, R = right, ans = 0, N = s.size();
        while (L >= 0 and R < N and s[L] == s[R])
            ans++, L--, R++;
        return ans;
    }
    int countSubstrings(string s)
    {
        int ans = 0, N = s.size();
        for (int i = 0; i < N; i++)
        {
            ans += expandAroundCenter(i, i, s);
            if (i < N - 1)
                ans += expandAroundCenter(i, i + 1, s);
        }
        return ans;
    }
};