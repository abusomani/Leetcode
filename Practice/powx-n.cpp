class Solution
{
public:
    double power(double x, long n)
    {
        double ans = 1, a = x;
        while (n)
        {
            if (n & 1)
                ans *= a;
            a *= a;
            n >>= 1;
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }
};