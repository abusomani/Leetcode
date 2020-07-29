class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0 or num == 2)
            return false;
        if (num == 1)
            return true;
        double N = fabs(num);
        double p = log(N) / log(4);
        int P = p;
        return (fabs(P - p) < 1e-5) ? true : false;
    }
};