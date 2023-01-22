class Solution
{
private:
    vector<long> computePrefix(vector<int> &nums)
    {
        vector<long> prefix;
        prefix.push_back(0);
        for (auto &num : nums)
            prefix.push_back(prefix.back() + num);

        return prefix;
    }

public:
    int splitArray(vector<int> &nums, int M)
    {
        return iterativeDP(nums, M);
    }

    int iterativeDP(vector<int> &nums, int M)
    {
        // [M subarrays, all (M-1) of size 1 and last would be = N-M+1]
        int N = nums.size();
        // minimum largest sum including first i elements having j non overlapping intervals
        vector<vector<long>> dp(N + 1, vector<long>(M + 1, INT_MAX));
        vector<long> prefix = computePrefix(nums);

        // sum including 0 elements, with 0 intervals
        dp[0][0] = 0;

        for (int i = 1; i <= N; i++)        // including first i elements
            for (int j = 1; j <= M; j++)    // j non overlapping intervals
                for (int k = 0; k < i; k++) // go over all possible k's
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix[i] - prefix[k]));

        return (int)dp[N][M];
    }
};