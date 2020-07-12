class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int N = grid.size() , M = grid[0].size(), ans = 0;
        // fix two rows and take a vertical line traversal .
        // If number of points with both 1 in both rows are let say N
        // NC2 rectangles can be formed. 
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++) {
                int cnt = 0;
                for(int k=0;k<M;k++)
                    if(grid[i][k] and grid[j][k])cnt++;
                
                ans += (cnt * (cnt -1))/2;
            }
        }
        
        return ans;
    }
};