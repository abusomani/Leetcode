class Solution
{
public:
    // Trick is to only have the two minimum amongst all K numbers
    int minCostII(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (N == 0)
            return 0;
        int K = costs[0].size(), m1 = 0, m2 = 0;
        vector<int> dp(K, 0);

        for (int i = 0; i < N; i++)
        {
            int t1 = m1, t2 = m2;
            m1 = INT_MAX;
            m2 = INT_MAX;
            for (int j = 0; j < K; j++)
            {
                dp[j] = ((dp[j] != t1) ? t1 : t2) + costs[i][j];
                if (m1 > dp[j])
                {
                    m2 = m1;
                    m1 = dp[j];
                }
                else if (m2 > dp[j])
                    m2 = dp[j];
            }
        }

        return m1;
    }
};