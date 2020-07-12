class Solution
{
public:
    vector<int> prefixSum(vector<int> &A)
    {
        vector<int> pre(A.size() + 1);
        pre[0] = {0};
        for (int i = 1; i <= A.size(); i++)
            pre[i] = pre[i - 1] + A[i - 1];

        return pre;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int> &A, int k)
    {
        return maxSumOfMSubarrays(A, k, 3);
    }

    vector<int> maxSumOfMSubarrays(vector<int> &A, int K, int M = 3)
    {
        int N = A.size();
        if (N == 0 or K == 0 or M == 0)
            return {};

        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        vector<vector<int>> index(M + 1, vector<int>(N + 1, 0));

        vector<int> sum = prefixSum(A);

        /**
         * dp[i][j] = maximum sum we can get by i non overlapping arrays of size K till index j
         */
        for (int i = 1; i <= M; i++)
        {

            for (int j = i * K; j <= N; j++)
            {

                int current = dp[i - 1][j - K] + sum[j] - sum[j - K]; // if we include this element
                // then sum of (i-1) non overlapping till (j-K) index + (sum[j] - sum[j-K]) i.e. sum of this K

                if (current > dp[i][j - 1])
                {
                    dp[i][j] = current;
                    index[i][j] = j - K;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    index[i][j] = index[i][j - 1];
                }
            }
        }

        vector<int> subArrayIndex(M);
        subArrayIndex[M - 1] = index[M][N];

        for (int i = M - 2; i >= 0; i--)
        {
            subArrayIndex[i] = index[i + 1][subArrayIndex[i + 1]]; // with (i+1 arrays ending at subArrayIndex[i+1])
        }

        return subArrayIndex;
    }
};