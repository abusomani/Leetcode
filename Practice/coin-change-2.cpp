class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int dfs(int amount, int currSum, int pos, vector<int> &coins)
    {
        if (dp.count(currSum) and dp[currSum].count(pos))
            return dp[currSum][pos];

        if (currSum > amount)
            return dp[currSum][pos] = 0;
        if (currSum == amount)
            return dp[currSum][pos] = 1;

        int ways = 0;
        for (int i = pos; i < coins.size(); i++)
            if (coins[i] + currSum <= amount)
                ways += dfs(amount, currSum + coins[i], i, coins);

        return dp[currSum][pos] = ways;
    }
    int change(int amount, vector<int> &coins)
    {
        return dfs(amount, 0, 0, coins);
    }
};