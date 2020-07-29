class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        return (n % 3 == 0 and isPowerOfThree(n / 3));
    }
};

class Solution1
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        long x = 1;
        while (x < n)
            x *= 3;
        return x == n;
    }
};