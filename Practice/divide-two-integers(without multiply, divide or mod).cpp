class Solution
{
public:
    unsigned int absu(int value)
    {
        return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
    }
    int divide(int dividend, int divisor)
    {
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN and divisor == -1)
            return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);
        unsigned int divid = absu(dividend);
        unsigned int divis = absu(divisor);

        long ans = 0;
        while (divid >= divis)
        {
            long cnt = 1, div = divis;
            while (div + div <= divid)
            {
                div += div;
                cnt += cnt;
            }
            ans += cnt;
            divid -= div;
        }

        return sign ? -ans : ans;
    }
};