class Solution {
private:
    int N, M;
    vector<vector<vector<int>>> dp;
    bool isValid(int x, int V) {
        return x >= 0 and x < V;
    }
public:
    int dfs(int r, int c1, int c2, vector<vector<int>> &grid) {
        if(!isValid(r, N) or !isValid(c1, M) or !isValid(c2, M))
            return 0;
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        int mx = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2], val = 0;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                val = max(val, mx + dfs(r+1, c1+i, c2+j, grid));
        
        return dp[r][c1][c2] = val;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        dp.resize(N, vector<vector<int>>(M, vector<int>(M, -1)));
        return dfs(0,0,M-1, grid);
    }
};