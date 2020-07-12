class Solution
{
public:
    int process(int left, int right, vector<int> &A, vector<vector<int>> &dp)
    {
        if (left + 1 == right)
            return dp[left][right] = 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int mx = 0;
        for (int i = left + 1; i < right; i++)
        {
            int coins = A[left] * A[i] * A[right];
            mx = max(mx, coins + process(left, i, A, dp) + process(i, right, A, dp));
        }
        dp[left][right] = mx;
        return dp[left][right];
    }

    int maxCoins(vector<int> &nums)
    {
        int N = nums.size() + 2;
        vector<int> A(N, 1);
        vector<vector<int>> dp(N, vector<int>(N, -1));
        for (int i = 0; i < nums.size(); i++)
            A[i + 1] = nums[i];
        return process(0, N - 1, A, dp);
    }
};