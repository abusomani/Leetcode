class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j]=index;
        int count = dfs(grid, i+1, j, index) + 
                    dfs(grid, i-1, j, index) + 
                    dfs(grid, i, j+1, index) + 
                    dfs(grid, i, j-1, index);
        return count+1;
    }
    
    void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
		//finding adjacent island groups
        int n=grid.size();
        if(i>0) s.insert(grid[i-1][j]);
        if(j>0) s.insert(grid[i][j-1]);
        if(i<n-1) s.insert(grid[i+1][j]);
        if(j<n-1) s.insert(grid[i][j+1]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), res=0, index=2, count;
        map<int, int> area;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    area[index]=dfs(grid, i, j, index);
                    res=max(res, area[index++]);
					//if the grid is one large island, we would find the maximum size island here
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    set<int> s;
                    findNeighbours(grid, i, j, s);
                    count=1;    //to account for the converted island
                    for(int i:s)
                        count+=area[i];       // count the number of islands in the adjacent groups
                    res=max(res, count);
                }
            }
        }
        
        return res;
    }
};
