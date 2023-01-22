class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == -1)
            return dividend == INT_MAX ? INT_MIN : dividend == INT_MIN ? INT_MAX : -dividend;

        bool sign = (dividend ^ divisor) >= 0;
        return (!sign ? -1 : 1) * exp(log(fabs(dividend)) - log(fabs(divisor)));
    }
};