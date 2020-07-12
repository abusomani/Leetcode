class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int N = numCourses;
        vector<vector<int>> graph(N, vector<int>());
        for (auto course : prerequisites)
        {
            graph[course[1]].push_back(course[0]); // course1 before course0
        }
        vector<int> color(N, 0); // all white
        // Topological sort of all nodes with no cycles
        for (int i = 0; i < N; i++)
        {
            if (!color[i] and hasCycle(graph, color, i))
                return false;
        }

        return true;
    }

    bool hasCycle(vector<vector<int>> &graph, vector<int> &color, int src)
    {
        color[src] = 1; // GRAY

        for (int i = 0; i < graph[src].size(); i++)
        {
            int toNode = graph[src][i];

            // if being processed
            if (color[toNode] == 1)
                return true;

            // if not visited but ends up having cycle
            else if (color[toNode] == 0 and hasCycle(graph, color, toNode))
                return true;
        }

        color[src] = 2; // BLACK
        return false;
    }
};