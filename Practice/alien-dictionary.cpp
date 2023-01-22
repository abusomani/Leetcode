class Solution
{
public:
    string topologicalSort(map<char, int> &Indegree, map<char, set<char>> &graph)
    {
        string topo;
        queue<char> Q;
        for (auto it : Indegree)
            if (it.second == 0)
                Q.push(it.first);

        while (!Q.empty())
        {
            char ch = Q.front();
            Q.pop();

            topo += string(1, ch);

            for (auto neighbor : graph[ch])
            {
                if (--Indegree[neighbor] == 0)
                    Q.push(neighbor);
            }
        }

        // all nodes should be processed, else there is a cycle
        return topo.size() == Indegree.size() ? topo : "";
    }
    string alienOrder(vector<string> &words)
    {
        const int N = words.size();
        if (N == 0)
            return "";

        map<char, int> Indegree;
        map<char, set<char>> graph;

        for (auto &word : words)
            for (auto &c : word)
                Indegree[c] = 0, graph[c] = {}; // initialization

        for (int i = 0; i < N - 1; i++)
        {
            string curr = words[i];
            string next = words[i + 1];
            int minLen = min((int)curr.size(), (int)next.size());
            int j = 0;
            for (; j < minLen; j++)
            {
                // post this we would break
                if (curr[j] != next[j])
                {
                    //directed node
                    if (!graph[curr[j]].count(next[j]))
                    {
                        graph[curr[j]].insert(next[j]);
                        Indegree[next[j]]++;
                    }
                    break;
                }
            }
            // current's length is greater than next, and all characters are equal
            if (j == next.size() and curr.size() > j)
                return "";
        }

        return topologicalSort(Indegree, graph);
    }
};