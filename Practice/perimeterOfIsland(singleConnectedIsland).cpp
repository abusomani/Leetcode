class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int N = grid.size(), M = N ? grid[0].size() : 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) {
                if(grid[i][j] == 1) {
                    int common = 4;
                    if(isValid(i-1,j,N,M,grid))common--;
                    if(isValid(i+1,j,N,M,grid))common--;
                    if(isValid(i,j-1,N,M,grid))common--;
                    if(isValid(i,j+1,N,M,grid))common--;
                    ans += common;
                }
            }
        }
        return ans;
    }
private:
    bool isValid(int i,int j, int N, int M, vector<vector<int>>& grid) {
        return (i >= 0 and i < N and j >= 0 and j < M and grid[i][j] == 1);
    }
};