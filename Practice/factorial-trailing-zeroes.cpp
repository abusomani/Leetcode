class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        long x = 5, N = n;
        while (x <= N)
        {
            res += N / x;
            x *= 5;
        }
        return res;
    }
};