class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int N = nums.size(), lis_len = 1, res = 0;
        vector<int> len(N, 1), dp(N, 1);
        for (int i = 1; i < N; i++)
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (len[j] + 1 > len[i])
                    {
                        len[i] = len[j] + 1;
                        dp[i] = dp[j];
                    }
                    else if (len[j] + 1 == len[i])
                        dp[i] += dp[j];
                }
                lis_len = max(lis_len, len[i]);
            }
        for (int i = 0; i < N; i++)
            if (len[i] == lis_len)
                res += dp[i];
        return res;
    }
};