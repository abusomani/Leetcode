/*
My understanding of why dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1 is:

Let dp[m][k] = n, dp[m-1][k-1] = n0, dp[m-1][k] = n1.
When we have dp[m][k] = n, it actually means we can check the floors in the range of [0, n], which maximally contains n + 1 floors.

Suppose at the mth step, we throw the egg at floor i.

If egg breaks, we should now check the floors in [0, i], which contains i + 1 floors.
If egg doesn't break, we should now check the floors in [i + 1, n], which contains n - i floors.
We definitely want to maximize the (i + 1) and (n - i) values so that finally we can get the maximum n. That's why we can relate these two values with n0 and n1, because they are the best answers in the subproblems.

If egg breaks, we shall have i + 1 = n0 + 1, which indicates i = n0.
If egg doesn't break, we shall have n - i = n1 + 1, which indicates n = n1 + i + 1 = n0 + n1 + 1.
Therefore dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1.
*/
class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int i = K; i >= 1; i--)
                dp[i] += dp[i - 1] + 1;

        return m;
    }
};