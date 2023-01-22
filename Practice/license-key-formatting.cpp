class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string formatted, res;
        for (auto &c : S)
            if (c != '-')
                formatted += isdigit(c) ? c : toupper(c);
        int cnt = 0, N = formatted.size();
        for (int i = N - 1; i >= 0; i--)
        {
            if (cnt == K)
                res += "-", cnt = 0;
            res += formatted[i], cnt++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};