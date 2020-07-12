class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2, n = A.size();
        // dp[diff][index] equals to the maximum length of arithmetic sequence at index with difference diff.
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int d = A[j] - A[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(res, dp[d][j]);
            }
        return res;
    }

    int longestArithSeqLength1(vector<int> &A)
    {
        if (A.size() < 2)
        {
            return A.size();
        }

        vector<unordered_map<int, int>> dp(A.size());
        int maxRes = 0;

        for (int i = 1; i < A.size(); ++i)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int diff = A[i] - A[j];
                if (dp[j].find(diff) != dp[j].end())
                {
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                }
                else
                {
                    dp[i][diff] = max(dp[i][diff], 2);
                }

                maxRes = max(maxRes, dp[i][diff]);
            }
        }

        return maxRes;
    }
};