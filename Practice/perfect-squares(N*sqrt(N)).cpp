/*
here is the Lagrange's Four Square theorem - Limit the result to <= 4:
https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
*/
typedef long long ll;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);

        return dp[n];
    }
};