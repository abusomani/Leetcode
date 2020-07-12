typedef long long ll;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        int M = INT_MAX;
        vector<ll> dp;
        for (ll i = 1; i <= M; i *= 2)
            for (ll j = i; j <= M; j *= 3)
                for (ll k = j; k <= M; k *= 5)
                    dp.push_back(k);
        sort(dp.begin(), dp.end());
        return dp[n - 1];
    }
};