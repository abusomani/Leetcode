/*
In a N x N grid representing a field of cherries, each cell is one of three possible integers.

 

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
 

Your task is to collect maximum number of cherries possible by following the rules below:

 

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
 

 

Example 1:

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
 

Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.


Counter for greedy 1dp from top and 1 dp from bottom right
11100
00101
10100
00100
00111
*/
class Solution
{
public:
    int dfsDP(vector<vector<vector<int>>> &dp,
              vector<vector<int>> &grid, int N, int r1, int r2, int c1)
    {
        int c2 = (r1 + c1 - r2);
        if (r1 >= N or r2 >= N or c1 >= N or c2 >= N or grid[r1][c1] == -1 or grid[r2][c2] == -1)
            return INT_MIN;

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        if (r1 == N - 1 and c1 == N - 1)
            return grid[r1][c1];
        if (r2 == N - 1 and c2 == N - 1)
            return grid[r2][c2];
        int cherries = 0;
        if (r1 == r2 and c1 == c2)
        {
            cherries = grid[r1][c1];
        }
        else
        {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        cherries += max(
            max(dfsDP(dp, grid, N, r1 + 1, r2 + 1, c1), dfsDP(dp, grid, N, r1, r2, c1 + 1)),
            max(dfsDP(dp, grid, N, r1 + 1, r2, c1), dfsDP(dp, grid, N, r1, r2 + 1, c1 + 1)));

        dp[r1][c1][r2] = cherries;
        return dp[r1][c1][r2];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int N = grid.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
        return max(0, dfsDP(dp, grid, N, 0, 0, 0));
    }
};