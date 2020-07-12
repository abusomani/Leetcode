class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 0)
            return 0;
        vector<int> dp(N, 1);
        int ans = 1;
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};