class Solution
{
public:
    bool validPalindrome(string s)
    {
        int N = s.size();
        if (N <= 2)
            return true;
        int i = 0, j = N - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else // mismatch
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