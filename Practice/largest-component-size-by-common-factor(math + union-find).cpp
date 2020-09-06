class Solution
{
private:
    int MAXN;
    vector<int> ID, SZ;
    vector<bool> notPrime;
    int Find(int a)
    {
        while (ID[a] != a)
        {
            ID[a] = ID[ID[a]];
            a = ID[a];
        }
        return a;
    }
    void Union(int a, int b)
    {
        int parentA = Find(a), parentB = Find(b);
        if (parentA == parentB)
            return;
        if (SZ[parentA] > SZ[parentB])
        {
            ID[parentB] = ID[parentA];
            SZ[parentA] += SZ[parentB];
        }
        else
        {
            ID[parentA] = ID[parentB];
            SZ[parentB] += SZ[parentA];
        }
    }
    void mark(int N, unordered_set<int> &St)
    {
        for (int i = N; i < MAXN; i += N)
        {
            notPrime[i] = true;
            if (St.count(i))
                Union(N, i);
        }
    }
    void sieve(vector<int> &A)
    {
        unordered_set<int> St(A.begin(), A.end());
        mark(2, St);
        for (int i = 3; i * i <= MAXN; i += 2)
            if (!notPrime[i])
                mark(i, St);
        for (int i = sqrt(MAXN); i < MAXN; i++)
            if (!notPrime[i])
                mark(i, St);
    }

public:
    int largestComponentSize(vector<int> &A)
    {
        int N = A.size(), ans = 0, mx = -1;
        for (auto &i : A)
            mx = max(mx, i);
        MAXN = mx + 1;
        notPrime.resize(MAXN, false);
        ID.resize(MAXN);
        for (int i = 0; i < MAXN; i++)
            ID[i] = i;
        SZ.resize(MAXN, 0);
        for (auto &i : A)
            SZ[i] = 1;
        sieve(A);
        for (auto &i : SZ)
            ans = max(ans, i);
        return ans;
    }
};