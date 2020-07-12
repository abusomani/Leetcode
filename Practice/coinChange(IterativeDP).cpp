typedef long long ll;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        int N = coins.size();
        vector<ll> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};