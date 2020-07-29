class Solution
{
private:
    void mark(int N, int MAX)
    {
        for (int i = N * N; i < MAX; i += N)
            Primes[i] = false;
    }
    void sieve(int N)
    {
        Primes.resize(N);
        for (int i = 0; i < N; i++)
            Primes[i] = true;
        Primes[0] = Primes[1] = false;
        mark(2, N);
        for (int i = 3; i <= sqrt(N); i += 2)
            if (Primes[i])
                mark(i, N);
    }

public:
    vector<bool> Primes;
    int countPrimes(int n)
    {
        if (n <= 1)
            return 0;
        sieve(n);
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (Primes[i])
                ans++;

        return ans;
    }
};