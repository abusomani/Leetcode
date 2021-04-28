class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& O) {
        int i = 0, j = 0, N = O.size(), M = O[0].size();
        if(O[i][j] == 1 or O[N-1][M-1] == 1)
            return 0; // first place or destination is obstacle itself
        vector<vector<int>> dp(N, vector<int>(M, 0));
        dp[0][0] = 1; // 1-way
        for(int i=1; i<N and O[i][0] != 1; i++)
            dp[i][0] = 1;
        for(int i=1; i<M and O[0][i] != 1; i++)
            dp[0][i] = 1;
        for(int i=1; i<N; i++)
            for(int j=1; j<M; j++) {
                if(O[i][j] == 1)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[N-1][M-1];
    }
};