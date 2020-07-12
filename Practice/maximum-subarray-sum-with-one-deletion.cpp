class Solution
{
public:
    int maximumSum(vector<int> &A)
    {
        const int N = A.size();
        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][0] = A[0];
        int res = A[0];
        for (int i = 1; i < N; i++)
        {
            dp[i][0] = max(A[i], dp[i - 1][0] + A[i]); // new subarray or add to previous
            dp[i][1] = max(A[i], max(dp[i - 1][1] + A[i], dp[i - 1][0]));
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};