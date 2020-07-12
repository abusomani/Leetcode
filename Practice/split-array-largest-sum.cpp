//Time complexity : O(n^2 * m)
class Solution
{
private:
    vector<long> prefix;

public:
    void computePrefix(vector<int> &nums)
    {
        prefix.push_back(0);
        for (auto &num : nums)
            prefix.push_back(prefix.back() + num);
    }
    int splitArray(vector<int> &nums, int m)
    {
        const int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<vector<long>> dp(n + 1, vector<long>(m + 1, INT_MAX));
        computePrefix(nums);

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 0; k < i; k++)
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix[i] - prefix[k]));

        return (int)dp[n][m];
    }
};