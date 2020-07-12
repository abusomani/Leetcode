class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int N = numCourses;
        vector<vector<int>> graph(N, vector<int>());
        vector<int> indegree(N, 0);
        int visitedNode = 0;
        for (auto course : prerequisites)
        {
            indegree[course[0]]++;
            graph[course[1]].push_back(course[0]);
        }
        vector<int> result;
        queue<int> Q;

        for (int i = 0; i < N; i++)
            if (!indegree[i])
                Q.push(i);

        while (!Q.empty())
        {
            int node = Q.front();
            result.push_back(node);
            Q.pop();
            visitedNode++;

            for (int i = 0; i < graph[node].size(); i++)
            {
                if (--indegree[graph[node][i]] == 0)
                    Q.push(graph[node][i]);
            }
        }

        return visitedNode == N ? result : vector<int>();
    }
};