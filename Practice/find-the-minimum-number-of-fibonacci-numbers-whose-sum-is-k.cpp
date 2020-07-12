#define ll long long
class Solution
{
    vector<int> fib;

public:
    int minFibonacciNumbers(ll K)
    {
        int count = 0, j = fib.size() - 1;
        while (K)
        {
            count += (K / fib[j]);
            K %= (fib[j]);
            j--;
        }
        return count;
    }
    void generateFibonacci(ll K)
    {
        int i = 3;
        fib.push_back(0);
        fib.push_back(1);
        fib.push_back(1);
        while (true)
        {
            ll c = fib[i - 1] + fib[i - 2];
            if (c > K)
                return;
            fib.push_back(c);
            i++;
        }
    }
    int findMinFibonacciNumbers1(int k)
    {
        generateFibonacci(k);
        return minFibonacciNumbers(k);
    }
    int findMinFibonacciNumbers(int k)
    {
        if (k < 2)
            return k;
        int a = 1, b = 1;
        while (b <= k)
        {
            swap(a, b);
            b += a;
        }
        return 1 + findMinFibonacciNumbers(k - a);
    }
};