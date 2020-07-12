class Solution
{
public:
    void dfs(unordered_map<string, unordered_set<string>> &graph, string src, unordered_set<string> &visited, set<string> &path)
    {
        path.insert(src);

        for (auto s : graph[src])
            if (!visited.count(s))
            {
                visited.insert(s);
                dfs(graph, s, visited, path);
            }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, unordered_set<string>> graphOfEmails;
        unordered_map<string, string> emailToName;

        int N = accounts.size();
        for (int i = 0; i < N; i++)
        {
            string name = accounts[i][0];
            int M = accounts[i].size();
            for (int j = 1; j < M; j++) // undirected edge between j and j-1
            {
                if (!graphOfEmails.count(accounts[i][j])) // if first time then just make an empty set
                    graphOfEmails[accounts[i][j]] = {};
                if (j > 1) // adjacent emails have edges
                {
                    graphOfEmails[accounts[i][j]].insert(accounts[i][j - 1]);
                    graphOfEmails[accounts[i][j - 1]].insert(accounts[i][j]);
                }
                emailToName[accounts[i][j]] = name;
            }
        }

        vector<vector<string>> result;
        unordered_set<string> visited;
        // find connected components
        for (auto emails : graphOfEmails)
        {
            if (!visited.count(emails.first))
            {
                set<string> path;
                vector<string> V;
                V.push_back(emailToName[emails.first]);
                dfs(graphOfEmails, emails.first, visited, path);
                for (auto i : path)
                    V.push_back(i);
                result.push_back(V);
            }
        }

        return result;
    }
};