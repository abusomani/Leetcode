class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // dp[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        // build up from shorter ranges to longer ranges
        for (int len = 1; len <= N; ++len)
        {
            for (int start = 1; start <= N - len + 1; ++start)
            {
                int end = start + len - 1;
                // calculate the max # of coins that can be obtained by
                // popping balloons only in the range [start,end].
                // consider all possible choices of final balloon to pop
                int bestCoins = 0;
                for (int final = start; final <= end; ++final)
                {
                    int coins = dp[start][final - 1] + dp[final + 1][end];  // coins from popping subranges
                    coins += nums[start - 1] * nums[final] * nums[end + 1]; // coins from final pop
                    if (coins > bestCoins)
                        bestCoins = coins;
                }
                dp[start][end] = bestCoins;
            }
        }
        return dp[1][N];
    }
};