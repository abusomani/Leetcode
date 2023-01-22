class Solution
{
private:
    vector<int> computePrefix(vector<int> &nums)
    {
        vector<int> prefix;
        prefix.push_back(0);
        for (auto &num : nums)
            prefix.push_back(prefix.back() + num);

        return prefix;
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        return maxSumOfMSubarrays(nums, 3, k);
    }
    vector<int> maxSumOfMSubarrays(vector<int> &nums, int M, int k)
    {
        int N = nums.size();
        if (N == 0 or M == 0 or k == 0)
            return {};

        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        vector<vector<int>> index(M + 1, vector<int>(N + 1, 0));

        vector<int> prefix = computePrefix(nums);

        /**
         * dp[i][j] = maximum sum we can get by i non overlapping arrays of size k till index j
         */
        for (int i = 1; i <= M; i++)
        {
            for (int j = i * k; j <= N; j++)
            {
                int val = dp[i - 1][j - k] + prefix[j] - prefix[j - k];
                if (val > dp[i][j - 1])
                {
                    dp[i][j] = val;
                    index[i][j] = j - k; // start of this array
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    index[i][j] = index[i][j - 1];
                }
            }
        }

        vector<int> idx(M);
        idx[M - 1] = index[M][N];
        for (int i = M - 2; i >= 0; i--)
            idx[i] = index[i + 1][idx[i + 1]];

        return idx;
    }
};