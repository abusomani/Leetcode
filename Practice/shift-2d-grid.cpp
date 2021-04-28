class Solution {
private:
    int N, M;
    void modifyColumn(vector<vector<int>>& grid, int column){
        int tmp = grid[N-1][column];
        for(int i=N-1; i>=1; i--)
            grid[i][column] = grid[i-1][column];
        grid[0][column] = tmp;
    }
    void copy(vector<vector<int>> &dp, vector<vector<int>> &grid, int cTo, int cFrom){
        for(int i=0;i <N; i++)
            dp[i][cTo] = grid[i][cFrom];
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        N = grid.size(), M = grid[0].size();
        int last = M-1;
        for(int i=0; i<k; i++, last = (last-1+M)%M)
            modifyColumn(grid, last);
        
        vector<vector<int>> dp(N, vector<int>(M));
        int idx = k%M;
        for(int i=idx; i<(M+idx); i++) {
            copy(dp, grid, i%M, i-idx);
        }
        return dp;
    }
};