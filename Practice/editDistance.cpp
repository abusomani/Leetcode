class Solution
{
public:
    int editDist(vector<vector<int>> &dp, string a, string b, int i, int j)
    {
        if (i == 0)
            return dp[i][j] = j;
        if (j == 0)
            return dp[i][j] = i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i - 1] == b[j - 1])
            return dp[i][j] = editDist(dp, a, b, i - 1, j - 1);
        else
            return dp[i][j] = 1 + min(editDist(dp, a, b, i, j - 1),
                                      min(editDist(dp, a, b, i - 1, j),
                                          editDist(dp, a, b, i - 1, j - 1)));
    }
    int minDistance(string word1, string word2)
    {
        int N = word1.size(), M = word2.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dp[i][j] = -1;
        editDist(dp, word1, word2, N, M);
        return dp[N][M];
    }
};