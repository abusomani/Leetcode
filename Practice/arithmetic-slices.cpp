class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int N = A.size();
        if (N < 2)
            return 0;
        int res = 0;
        vector<int> dp(N, 0);
        for (int i = 2; i < N; i++)
        {
            // if A[i-2], A[i-1], A[i] are arithmetic then
            // dp[i] = slices ending at (i-1) i.e. dp[i-1](as all can be appended with A[i]) + 1
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                res += 1 + dp[i - 1], dp[i] = 1 + dp[i - 1];
        }
        return res;
    }
};