class Solution {
private:
    int x, y;
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int dfs(vector<vector<int>>& A, int i,int j, vector<vector<int>>& dp)
    {
        if(dp[i][j] != 0)
            return dp[i][j];
        int maxLen = 1;
        for(int dir=0;dir<4;dir++)
        {
            x = i + dx[dir];
            y = j + dy[dir];
            if(x >= 0 and x < A.size() and y >= 0 and y < A[0].size()
              and A[i][j] < A[x][y])
                maxLen = max(maxLen, 1 + dfs(A, x, y, dp));
        }
        return dp[i][j] = maxLen; // because number itself is always counted
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = N ? matrix[0].size() : 0;
        if(N == 0 or M == 0)
            return 0;
        vector<vector<int>> dp(N, vector<int>(M, 0)); // all zeros
        int ans = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                ans = max(ans, dfs(matrix, i, j, dp));
        
        return ans;
    }
};