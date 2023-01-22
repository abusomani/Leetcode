class Solution
{
public:
    int titleToNumber(string s)
    {
        int ans = 0, mul = 26, N = s.size();
        for (int i = 0; i < N; i++) // multiply answer by 26 and add (s[i] - 'A' + 1)
            ans = ans * 26 + (s[i] - 'A' + 1);

        return ans;
    }
};