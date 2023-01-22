class Solution
{
public:
    void BFS(int src, vector<vector<int>> &friends, vector<int> &visited)
    {
        queue<int> Q;
        visited[src] = 1;
        Q.push(src);
        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz--)
            {
                int node = Q.front();
                Q.pop();
                for (int i = 0; i < friends[node].size(); i++)
                {
                    if (friends[node][i] == 1 and !visited[i])
                    {
                        Q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &friends)
    {
        int circles = 0, N = friends.size(), M = N;
        vector<int> visited(N, 0);
        for (int i = 0; i < N; i++)
            if (visited[i] == 0)
                circles++, BFS(i, friends, visited);

        return circles;
    }
};