class Solution
{
private:
    int N;
    unordered_set<string> St;
    string s;
    vector<int> visited;
    void dfs(int len, string curr)
    {
        if (len == 0)
        {
            St.insert(curr);
            return;
        }
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            curr += s[i];
            dfs(len - 1, curr);
            curr.pop_back();
            visited[i] = false;
        }
    }

public:
    int numTilePossibilities(string tiles)
    {
        N = tiles.size();
        visited.resize(N, false);
        s = tiles;
        for (int len = 1; len <= N; len++)
        {
            dfs(len, "");
        }
        return (int)St.size();
    }
};