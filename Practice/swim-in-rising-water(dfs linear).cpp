class Solution
{
private:
    int gridSize;

public:
    void dfs(vector<vector<int>> &grid, int x, int y, int time, unordered_set<int> &visited)
    {
        int coord = x * gridSize + y;
        if (x >= 0 and x < gridSize and y >= 0 and y < gridSize and !visited.count(coord) and grid[x][y] <= time)
        {
            visited.insert(coord);
            dfs(grid, x, y + 1, time, visited);
            dfs(grid, x + 1, y, time, visited);
            dfs(grid, x, y - 1, time, visited);
            dfs(grid, x - 1, y, time, visited);
        }
    }
    // N * (N-1) + N-1 => N^2 - N + N - 1
    int swimInWater(vector<vector<int>> &grid)
    {
        gridSize = grid.size();
        unordered_set<int> visited;
        int dest = gridSize * gridSize - 1, time = -1;
        while (!visited.count(dest))
        {
            time++;
            visited.clear();
            dfs(grid, 0, 0, time, visited);
        }

        return time;
    }
};