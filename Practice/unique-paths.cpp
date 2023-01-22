class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m, vector<int> (n, 1));
        vector<int> prev(n, 1), curr(n, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                curr[j] = prev[j] + curr[j - 1];

            swap(prev, curr);
        }

        return prev[n - 1];
    }
};