class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;           // M moves;
        while (dp[m][K] < N) // K eggs and m moves is less than N floors
        {
            m++; // make a move
            for (int i = 1; i <= K; i++)
                dp[m][i] = dp[m - 1][i] + dp[m - 1][i - 1] + 1; // either egg breaks or not plus 1 move
        }

        return m;
    }
};