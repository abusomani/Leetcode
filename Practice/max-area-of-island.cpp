class Solution {
public:
    int dfs(vector<vector<int>> &grid, int x, int y){
        if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or grid[x][y] == 0)
            return 0;
        int cnt = 1;
        grid[x][y] = 0;
        cnt += dfs(grid, x-1, y);
        cnt += dfs(grid, x+1, y);
        cnt += dfs(grid, x, y-1);
        cnt += dfs(grid, x, y+1);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
                if(grid[i][j])
                    res = max(res, dfs(grid, i, j));
        return res;
    }
};