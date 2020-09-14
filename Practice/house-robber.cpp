class Solution
{
private:
    unordered_map<int, int> dp;
    int dfs(vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
            return 0;
        if (dp.count(idx))
            return dp[idx];
        return dp[idx] = max(dfs(nums, idx + 1), nums[idx] + dfs(nums, idx + 2));
    }

public:
    int rob(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return 0;
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        for (int i = 1; i < N; i++)
            dp[i] = max(dp[i - 1], nums[i] + (i >= 2 ? dp[i - 2] : 0));
        return dp[N - 1];
    }
};