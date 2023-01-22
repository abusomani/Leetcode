class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int i, int j, int N, int M)
    {
        return (i >= 0 and i < N and j >= 0 and j < M);
    }
    bool dfs(vector<vector<int>> &grid, int i, int j, int &N, int &M, int elevate, unordered_set<int> &visited)
    {
        // if source becomes destination, implies possible returns true
        if (i == N - 1 and j == M - 1)
            return true;

        // mark visited
        int coord = i * M + j;
        visited.insert(coord);
        for (int dir = 0; dir < 4; dir++)
        {
            int newX = i + dx[dir];
            int newY = j + dy[dir];
            int newCoord = newX * M + newY;

            // same as Graph based DFS
            if (isValid(newX, newY, N, M) and !visited.count(newCoord) and grid[newX][newY] <= elevate)
                if (dfs(grid, newX, newY, N, M, elevate, visited)) // early terminate
                    return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int N = grid.size();
        unordered_set<int> visited;
        int left = grid[0][0], right = INT_MAX;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            visited.clear();
            if (dfs(grid, 0, 0, N, N, mid, visited))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};