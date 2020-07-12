class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans = 0;
        int N = grid.size(), M = grid[0].size();
        int i = N - 1, j = 0; // start from bottom left corner

        while (i >= 0 and j < M)
        {
            if (grid[i][j] < 0)
            { // means entire row from jth position is negative
                ans += (M - j);
                i--;
            }
            else
            { // see in next column
                j++;
            }
        }

        return ans;
    }
};