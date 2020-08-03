// check if in the dfs of connected component of 0 all are visited or not
class Solution
{
public:
    void dfs(vector<vector<int>> &rooms, int src, vector<bool> &visited)
    {
        visited[src] = true;
        for (auto &i : rooms[src])
            if (!visited[i])
                dfs(rooms, i, visited);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int N = rooms.size();
        vector<bool> visited(N, false);
        dfs(rooms, 0, visited);

        for (int i = 0; i < N; i++)
            if (!visited[i])
                return false;

        return true;
    }
};

// Check number of nodes in the connected component of 0;
class Solution1
{
private:
    unordered_set<int> nodes;

public:
    void dfs(vector<vector<int>> &rooms, int src)
    {
        nodes.insert(src);
        for (auto &i : rooms[src])
            if (!nodes.count(i))
                dfs(rooms, i);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int N = rooms.size();
        dfs(rooms, 0);
        return nodes.size() == N;
    }
};