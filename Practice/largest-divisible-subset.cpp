class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> res;
        if (N == 0)
            return res;

        sort(nums.begin(), nums.end());
        vector<int> dp(N, 0);
        vector<int> parent(N, 0);
        int maxIndex = 0, max = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 and dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;

                    if (dp[i] > max)
                    {
                        max = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }

        for (int i = 0; i < max; i++)
        {
            res.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};