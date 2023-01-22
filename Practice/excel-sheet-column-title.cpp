class Solution
{
public:
    // Num = Num*26 + (s[i] - 'A' + 1)
    string convertToTitle(int n)
    {
        string res;
        while (n)
        {
            --n; // decrease one before at each step, as in formula it was added too
            res += (n % 26 + 'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};