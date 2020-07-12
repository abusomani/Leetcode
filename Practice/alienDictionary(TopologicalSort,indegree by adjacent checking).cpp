class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        if (words.size() == 0)
            return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;

        // initialize
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                indegree[c] = 0;
            }
        }

        // build graph and record indegree
        for (int i = 0; i < words.size() - 1; i++)
        {
            string cur = words[i];
            string nex = words[i + 1];
            int len = min(cur.size(), nex.size());
            for (int j = 0; j < len; j++)
            {
                if (cur[j] != nex[j])
                {
                    unordered_set<char> set = graph[cur[j]];
                    if (set.find(nex[j]) == set.end())
                    {
                        graph[cur[j]].insert(nex[j]); // build graph
                        indegree[nex[j]]++;           // add indegree
                    }
                    break;
                }
                if (j == len - 1 and cur[j] == nex[j] and cur.size() > nex.size())
                    return "";
            }
        }

        // topoligical sort
        string ans;
        queue<char> q;
        for (auto &e : indegree)
        {
            if (e.second == 0)
            {
                q.push(e.first);
            }
        }
        while (!q.empty())
        {
            char cur = q.front();
            q.pop();
            ans += cur;

            if (graph[cur].size() != 0)
            {
                for (auto &e : graph[cur])
                {
                    indegree[e]--;
                    if (indegree[e] == 0)
                    {
                        q.push(e);
                    }
                }
            }
        }

        // tell if it is cyclic
        return ans.length() == indegree.size() ? ans : "";
    }
};