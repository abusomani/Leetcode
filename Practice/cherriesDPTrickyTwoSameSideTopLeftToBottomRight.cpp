class Solution {
public:
    int dfsDP(vector<vector<vector<vector<int> > > > &dp,
              vector<vector<int>>& grid, int N, int r1, int r2,int c1,int c2) {
        
        if(r1 >= N or r2 >= N or c1>= N or c2 >= N or grid[r1][c1] == -1 or grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][r2][c2] != -1)return dp[r1][c1][r2][c2];
        if(r1 == N-1 and c1 == N-1)return grid[r1][c1];
        if(r2 == N-1 and c2 == N-1)return grid[r2][c2];
        int cherries = 0;
        if(r1 == r2 and c1 == c2) {
            cherries = grid[r1][c1];
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        cherries += max(
                        max(dfsDP(dp,grid,N,r1+1,r2+1,c1,c2),dfsDP(dp,grid,N,r1,r2,c1+1,c2+1)),
                        max(dfsDP(dp,grid,N,r1+1,r2,c1,c2+1),dfsDP(dp,grid,N,r1,r2+1,c1+1,c2))
                    );
        
        dp[r1][c1][r2][c2] = cherries;
        return dp[r1][c1][r2][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<vector<vector<int> > > > dp(N,vector<vector<vector<int> > >(N,vector<vector<int> >(N,vector<int>(N,-1))));
        return max(0,dfsDP(dp,grid,N,0,0,0,0));
    }
};