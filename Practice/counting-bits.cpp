class Solution
{
public:
    /*
    If we make last set bit as zero, then whatever number remains, we would have already computed that, because it must be lower
    so dp[i] = 1 + dp[i & (i-1)]
    */
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; i++)
            dp[i] += 1 + dp[(i & (i - 1))];
        return dp;
    }
};