class Solution
{
public:
    int reverse(int x)
    {
        long X = x, ans = 0;
        while (X)
        {
            ans = ans * 10 + X % 10;
            X /= 10;
        }

        if (ans > INT_MAX or ans < INT_MIN)
            return 0;
        return (int)ans;
    }
};