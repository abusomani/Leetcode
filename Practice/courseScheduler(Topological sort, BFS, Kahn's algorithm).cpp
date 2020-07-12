class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int N = numCourses;
        vector<vector<int>> graph(N, vector<int>());
        vector<int> indegree(N, 0);
        int visitedNodes = 0;
        for (auto course : prerequisites)
        {
            indegree[course[0]]++;
            graph[course[1]].push_back(course[0]); // course1 before course0
        }

        // Topological sort using BFS, Kahn's algorithm
        queue<int> Q;
        for (int i = 0; i < N; i++)
            if (!indegree[i])
                Q.push(i);

        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            visitedNodes++;
            for (int i = 0; i < graph[node].size(); i++)
            {
                if (--indegree[graph[node][i]] == 0)
                    Q.push(graph[node][i]);
            }
        }

        return visitedNodes == N;
    }
};