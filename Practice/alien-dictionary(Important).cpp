class Solution
{
public:
    string topologicalSort(unordered_map<char, int> &Indegree, unordered_map<char, unordered_set<char>> &graph)
    {
        string res;
        queue<char> Q;
        for (auto &i : Indegree)
            if (i.second == 0)
                Q.push(i.first);
        while (!Q.empty())
        {
            char ch = Q.front();
            Q.pop();
            res += ch;
            for (auto &c : graph[ch])
            {
                if (--Indegree[c] == 0)
                    Q.push(c);
            }
        }
        return res.size() == Indegree.size() ? res : "";
    }
    string alienOrder(vector<string> &words)
    {
        unordered_map<char, int> Indegree;
        for (auto &word : words)
            for (auto &c : word)
                Indegree[c] = 0;

        unordered_map<char, unordered_set<char>> graph;
        int U = Indegree.size(); // total characters
        for (int i = 0; i < words.size() - 1; i++)
        {
            string curr = words[i], next = words[i + 1];
            int minLen = min((int)curr.size(), (int)next.size()), l = 0;
            for (; l < minLen; l++)
            {
                if (curr[l] != next[l])
                {
                    if (!graph.count(curr[l]) or !graph[curr[l]].count(next[l]))
                    {
                        Indegree[next[l]]++;
                        graph[curr[l]].insert(next[l]);
                    }
                    break;
                }
            }
            if (l >= minLen and curr.size() > next.size())
                return "";
        }
        return topologicalSort(Indegree, graph);
    }
};