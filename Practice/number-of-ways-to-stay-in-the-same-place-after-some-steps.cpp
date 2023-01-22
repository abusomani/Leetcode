#define ll long long
const int MOD = 1e9 + 7;
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> cache;
    int process(int stepsLeft, int idx, int N)
    {
        if (cache.count(stepsLeft) and cache[stepsLeft].count(idx))
            return cache[stepsLeft][idx];
        if (idx < 0 or idx > N)
            return cache[stepsLeft][idx] = 0;
        if (stepsLeft == 0)
            return cache[stepsLeft][idx] = (idx == 0) ? 1 : 0;
        ll val = 0;
        val += process(stepsLeft - 1, idx, N) % MOD;     // stay there
        val += process(stepsLeft - 1, idx + 1, N) % MOD; // go right
        val += process(stepsLeft - 1, idx - 1, N) % MOD; // go left
        return cache[stepsLeft][idx] = val % MOD;
    }
    int numWays(int steps, int arrLen)
    {
        return process(steps, 0, arrLen - 1) % MOD;
    }
};