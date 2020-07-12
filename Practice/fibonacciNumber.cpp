class Solution
{
public:
    int fib(int N)
    {
        if (N <= 1)
            return N;
        int a = 0, b = 1, c;
        for (int i = 2; i <= N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};