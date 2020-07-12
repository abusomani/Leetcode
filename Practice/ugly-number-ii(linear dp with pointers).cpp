/*
    Reduce the problem of merging three sorted lists.
    Increase pointer of all the lists with that number.
    Like for 6, both two and three should be incremented
*/
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
        int two = 0, three = 0, five = 0;
        vector<ll> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int mn = min({dp[two] * 2, dp[three] * 3, dp[five] * 5});
            dp[i] = mn;
            if (mn == dp[two] * 2)
                two++;
            if (mn == dp[three] * 3)
                three++;
            if (mn == dp[five] * 5)
                five++;
        }
        return dp[n - 1];
    }
};