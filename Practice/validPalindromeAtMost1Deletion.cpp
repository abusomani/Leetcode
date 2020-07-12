class Solution
{
public:
    //
    bool validPalindrome(string s)
    {
        int N = s.size();
        for (int i = 0, j = N - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                int p = i + 1, q = j, a = i, b = j - 1;
                while (p < q and s[p] == s[q])
                    p++, q--;
                while (a < b and s[a] == s[b])
                    a++, b--;
                return (p >= q) or (a >= b);
            }
        }
        return true;
    }
};