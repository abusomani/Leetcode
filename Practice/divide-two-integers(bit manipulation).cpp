class Solution
{
public:
    int divide(int A, int B)
    {
        if (A == INT_MIN)
        {
            if (B == 1)
                return INT_MIN;
            if (B == -1)
                return INT_MAX;
            if ((B & 1) == 0)
            {
                A >>= 1;
                B >>= 1;
            }
            else
            {
                A += 1;
            }
        }
        if (B == INT_MIN)
            return 0;
        int a = abs(A), b = abs(B), res = 0; // A and B should not be INT_MIN when calling abs()
        for (int x = 30; x >= 0; x--)        // no need for x=31
            if ((a >> x) - b >= 0)           // no need for signed and unsigned transformation
                res += (1 << x), a -= (b << x);
        return (A > 0) == (B > 0) ? res : -res;
    }
};