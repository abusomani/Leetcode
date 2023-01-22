//No need for visited as its DAG, there wont be a cycle
class Solution
{
private:
    vector<vector<int>> paths;

public:
    void dfs(int src, int dest, vector<int> &path, vector<vector<int>> &G)
    {
        path.push_back(src);
        if (src == dest)
            paths.push_back(path);
        else
        {
            for (auto child : G[src])
                dfs(child, dest, path, G);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &G)
    {
        const int N = G.size();
        vector<int> path;
        dfs(0, N - 1, path, G);
        return paths;
    }
};