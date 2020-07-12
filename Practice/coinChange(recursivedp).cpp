class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
            return 0;
        vector<int> dp(amount, 0);
        return help(coins, amount, dp);
    }

    int help(vector<int> &coins, int remain, vector<int> &dp)
    {
        if (remain < 0)
            return -1;
        if (remain == 0)
            return 0;
        if (dp[remain - 1] != 0)
            return dp[remain - 1];
        int min = INT_MAX;
        for (int coin : coins)
        {
            int result = help(coins, remain - coin, dp);
            if (result >= 0 && result < min)
                min = 1 + result;
        }
        dp[remain - 1] = (min == INT_MAX ? -1 : min);
        return dp[remain - 1];
    }
};